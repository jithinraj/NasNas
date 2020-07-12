/**
* Created by Modar Nasser on 22/04/2020.
**/


#include "NasNas/core/Window.hpp"
#include "NasNas/core/App.hpp"

using namespace ns;

void AppWindow::onCreate() {
    sf::RenderTarget::initialize();

    setKeyRepeatEnabled(ns::Config::Window::key_repeat);
    setVerticalSyncEnabled(ns::Config::Window::vertical_sync);
    setMouseCursorVisible(ns::Config::Window::cursor_visible);
    setMouseCursorGrabbed(ns::Config::Window::cursor_grabbed);

    m_app_view.m_render_texture.create(ns::Config::Window::view_width, ns::Config::Window::view_height);

    m_clear_color = sf::Color::Black;
}

void AppWindow::onResize() {
    scaleView();
}

auto AppWindow::getAppView() const -> const Camera& {
    return m_app_view;
}

void AppWindow::setAppView(int v_width, int v_height) {
    m_app_view.setName("UI");
    m_app_view.reset(0, 0, v_width, v_height);
    m_app_view.resetViewport(0, 0, 1, 1);
}

void AppWindow::scaleView(){
    // wider than base window
    float vp_w = 0, vp_h = 0, vp_x = 0, vp_y = 0;
    float win_w = (float)getSize().x, win_h = (float)getSize().y;
    float screen_ratio = (float)ns::Config::Window::width / (float)ns::Config::Window::height;
    if (win_w / win_h > screen_ratio) {
        vp_w = win_h * screen_ratio / win_w;
        vp_x = (1 - vp_w) / 2;
        vp_h = 1;
        vp_y = 0;
    }
    // higher than usual window
    else {
        vp_w = 1;
        vp_x = 0;
        vp_h = win_w / screen_ratio / win_h;
        vp_y = (1 - vp_h)/2;
    }

    auto old_vp = m_app_view.m_base_viewport;
    // compute new viewport rectangle
    auto new_vp = ns::FloatRect(
            vp_x + old_vp.left * (1 - 2 * vp_x), vp_y + old_vp.top * (1 - 2 * vp_y),
            vp_w * old_vp.width, vp_h * old_vp.height
    );
    m_app_view.setViewport(new_vp);
}

auto AppWindow::getClearColor() const -> const sf::Color& {
    return m_clear_color;
}

void AppWindow::setClearColor(const sf::Color& color) {
    m_clear_color = color;
}
