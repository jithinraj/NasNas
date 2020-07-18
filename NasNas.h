/**
* Created by Modar Nasser on 23/04/2020.
**/

#pragma once

#define NS_DATA
#include "NasNas/data/Config.hpp"

#define NS_ECS
#include "NasNas/ecs/BaseEntity.hpp"
#include "NasNas/ecs/SpriteComponent.hpp"
#include "NasNas/ecs/ShapeComponent.hpp"

#define NS_TILEMAPPING
#include "NasNas/tilemapping/TiledMap.hpp"

#define NS_RESLIB
#include "NasNas/reslib/ResourceManager.hpp"

#define NS_CORE
#include "NasNas/core/App.hpp"
#include "NasNas/core/Camera.hpp"
#include "NasNas/core/Scene.hpp"
#include "NasNas/core/Layers.hpp"
#include "NasNas/core/BitmapText.hpp"
#include "NasNas/core/Window.hpp"
#include "NasNas/core/Logger.hpp"
#include "NasNas/core/Debug.hpp"