#include "UI/ViewControllers/SettingsViewController.hpp"

#include "Breaktime/BreaktimeDummy.hpp"
#include "GlobalNamespace/ColorChangeUIEventType.hpp"
#include "UnityEngine/GameObject.hpp"
#include "bsml/shared/BSML.hpp"
#include "bsml/shared/BSML/Components/ExternalComponents.hpp"
#include "bsml/shared/BSML/MainThreadScheduler.hpp"
#include "PluginConfig.hpp"

DEFINE_TYPE(Breaktime::UI, SettingsViewController);

using namespace Breaktime;
using namespace BSML;
using namespace UnityEngine;
using namespace UnityEngine::UI;

namespace Breaktime::UI {

    void SettingsViewController::DidActivate(bool firstActivation, bool addedToHierarchy,
                                        bool screenSystemEnabling) {
        if (firstActivation) {
            GameObject* container = CreateScrollableSettingsContainer(get_transform());

            TMPro::TextMeshProUGUI* text = BSML::Lite::CreateText(container->get_transform(), 
                                                                    "Settings", true, {0, 0}, {20, 15});
            text->set_fontSize(10.0f);

            BSML::Lite::CreateIncrementSetting(container->get_transform(), "Minimum Break Time", 1, 0.5f, getPluginConfig().minTime.GetValue(), 
            [](float f){ getPluginConfig().minTime.SetValue(f); });

            BSML::Lite::CreateIncrementSetting(container->get_transform(), "Image Opacity", 1, 0.1f, 
            getPluginConfig().ImageOpacity.GetValue(), true, true, 0.0f, 1.0f, {0, 0}, 
            [](float f){ getPluginConfig().ImageOpacity.SetValue(f); });
            
            BSML::Lite::CreateIncrementSetting(container->get_transform(), "Image ScaleX", 1, 0.1f, 
            getPluginConfig().ScaleX.GetValue(), true, false, 0.0f, 1.0f, {0, 0}, 
            [](float f){ getPluginConfig().ScaleX.SetValue(f); });
            
            BSML::Lite::CreateIncrementSetting(container->get_transform(), "Image ScaleY", 1, 0.1f, 
            getPluginConfig().ScaleY.GetValue(), true, false, 0.0f, 1.0f, {0, 0}, 
            [](float f){ getPluginConfig().ScaleY.SetValue(f); });

            BSML::Lite::CreateToggle(container->get_transform(), "Mod Enabled", getPluginConfig().Enabled.GetValue(), 
            [](bool b){ getPluginConfig().Enabled.SetValue(b); });

            BSML::Lite::CreateToggle(container->get_transform(), "Show Text", getPluginConfig().ShowText.GetValue(), 
            [](bool b){ getPluginConfig().ShowText.SetValue(b); });

            BSML::Lite::CreateToggle(container->get_transform(), "Play Sound", getPluginConfig().SoundEnabled.GetValue(), 
            [](bool b){ getPluginConfig().SoundEnabled.SetValue(b); });

            BSML::Lite::CreateToggle(container->get_transform(), "Fade Out", getPluginConfig().FadeOut.GetValue(), 
            [](bool b){ getPluginConfig().FadeOut.SetValue(b); });

            BSML::Lite::CreateColorPicker(container->get_transform(), "Image Color", getPluginConfig().ImageColor.GetValue(), 
            [](Color color, GlobalNamespace::ColorChangeUIEventType){ getPluginConfig().ImageColor.SetValue(color); });

            BSML::Lite::CreateColorPicker(container->get_transform(), "Text Color", getPluginConfig().TextColor.GetValue(), 
            [](Color color, GlobalNamespace::ColorChangeUIEventType){ getPluginConfig().TextColor.SetValue(color); });

            Button* testButton = BSML::Lite::CreateUIButton(container->get_transform(), "TEST", "PlayButton", [&](){
                BreaktimeDummy* dummy = new BreaktimeDummy();
                dummy->SpawnDummy();
            });
        }
    }

    void SettingsViewController::DidDeactivate(bool removedFromHierarchy, bool screenSystemDisabling)
    {
        
    }
    
}