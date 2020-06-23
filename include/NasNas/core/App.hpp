/**
* Created by Modar Nasser on 15/04/2020.
**/

#pragma once

#include "NasNas/data/AppComponent.hpp"
#include "NasNas/data/Rect.hpp"
#include "NasNas/data/Config.hpp"

#include "NasNas/core/Layers.hpp"
#include "NasNas/core/Scene.hpp"
#include "NasNas/core/Camera.hpp"
#include "NasNas/core/Window.hpp"
#include "NasNas/core/Debug.hpp"
#include "NasNas/ecs/BaseEntity.hpp"

namespace ns {

    class App {
    public:
        App();
        App(const std::string& title, int w_width, int w_height,
            int v_width=ns::Config::Window::view_width,
            int v_height=ns::Config::Window::view_height,
            int fps=ns::Config::Window::framerate_limit,
            int ups=ns::Config::Window::update_rate
        );
        ~App();

        const int W_WIDTH;
        const int W_HEIGHT;

        auto getTitle() -> std::string&;

        auto allScenes() -> std::vector<Scene*>&;
        auto allCameras() -> std::vector<Camera*>&;

        auto getInputs() -> std::vector<sf::Keyboard::Key>&;

        void run();

    protected:

        auto createScene(int width, int height) -> Scene*;

        auto createCamera(const std::string& name, int order, const IntRect& view, const FloatRect& viewport) -> Camera*;
        auto createCamera(const std::string& name, int order, const IntRect& view) -> Camera*;

        template<typename T>
        void addDebugText(T* var_address, const std::string& label,const sf::Vector2f& position, const sf::Color& color = ns::DebugTextInterface::color);

        template<typename T>
        void addDebugText(const T* var_address, const std::string& label,const sf::Vector2f& position, const sf::Color& color = ns::DebugTextInterface::color);

        template<typename T, typename ObjT>
        void addDebugText(
                ObjT* object_address,
                std::function<T(ObjT &)> method_address,
                const std::string& label,
                const sf::Vector2f& position,
                const sf::Color& color = ns::DebugTextInterface::color
        );

        template<typename T, typename ObjT>
        void addDebugText(ns::DebugText<T, ObjT>* debug_text);

        auto getWindow() -> AppWindow&;
        void toggleFullscreen();

        virtual void onEvent(sf::Event event) = 0;

        virtual void update() = 0;

    private:
        std::string m_title;
        int m_desired_fps;      // frame per second
        int m_ups;              // update per second
        bool m_fullscreen;
        AppWindow m_window;

        sf::Clock m_fps_clock;
        double m_dt;
        std::vector<Camera*> m_cameras;
        std::vector<Scene*> m_scenes;

        std::vector<DebugTextInterface*> m_debug_texts;

        std::vector<sf::Keyboard::Key> m_inputs;

        void storeInputs(sf::Event event);

        void render();
    };

    template<typename T>
    void App::addDebugText(T* var_address, const std::string& label, const sf::Vector2f& position, const sf::Color& color) {
        sf::Color old_color = ns::DebugTextInterface::color;
        ns::DebugTextInterface::color = color;
        m_debug_texts.push_back(new DebugText<T, char>(var_address, label, position));
        ns::DebugTextInterface::color = old_color;
    }
    template<typename T>
    void App::addDebugText(const T* var_address, const std::string& label, const sf::Vector2f& position, const sf::Color& color) {
        sf::Color old_color = ns::DebugTextInterface::color;
        ns::DebugTextInterface::color = color;
        m_debug_texts.push_back(new DebugText<T, char>(var_address, label, position));
        ns::DebugTextInterface::color = old_color;
    }
    template<typename T, typename ObjT>
    void App::addDebugText(ObjT* object_address, std::function<T(ObjT &)> method_address, const std::string& label, const sf::Vector2f& position, const sf::Color& color) {
        sf::Color old_color = ns::DebugTextInterface::color;
        ns::DebugTextInterface::color = color;
        m_debug_texts.push_back(new DebugText<T, ObjT>(object_address, method_address, label, position));
        ns::DebugTextInterface::color = old_color;
    }
    template<typename T, typename ObjT>
    void App::addDebugText(ns::DebugText<T, ObjT>* debug_text) {
        m_debug_texts.push_back(debug_text);
    }

}
