#pragma once

#include "TMPro/TextMeshProUGUI.hpp"
#include "bsml/shared/BSML.hpp"
#include "bsml/shared/BSML/Components/ExternalComponents.hpp"
#include "bsml/shared/BSML/MainThreadScheduler.hpp"
#include "UnityEngine/AudioSource.hpp"
#include "UnityEngine/AudioClip.hpp"
#include "UnityEngine/UI/Button.hpp"
#include "custom-types/shared/coroutine.hpp"
#include "HMUI/ImageView.hpp"
#include "Breaktime/BreaktimeManager.hpp"

using namespace custom_types;
using namespace UnityEngine;
using namespace UnityEngine::UI;
using namespace BSML;
using namespace TMPro;
using namespace HMUI;

namespace Breaktime {
    class BreaktimeDummy{
        public:
            BreaktimeDummy();  
            void SpawnDummy();
            TextMeshProUGUI* text;
            GameObject* screen;
            ImageView* image;
        private:
            bool createdUI = false;
            void CreateScreen();
            Helpers::Coroutine PlaySound();
    };
}