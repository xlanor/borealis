/*
    Copyright 2021 XITRIX

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

#pragma once

#include <borealis/core/application.hpp>
#include <borealis/core/bind.hpp>
#include <borealis/core/box.hpp>
#include <borealis/views/image.hpp>
#include <borealis/views/label.hpp>

namespace brls
{

class Hint : public Box
{
  public:
    Hint(std::shared_ptr<Action> action, bool allowAButtonTouch = false);
    static std::string getKeyIcon(ControllerButton button, bool ignoreKeysSwap = false);

    /* Zero for either leaves the XML's own size alone. */
    void setFontSizes(float iconSize, float textSize);

  private:
    std::shared_ptr<Action> action;

    BRLS_BIND(Label, icon, "icon");
    BRLS_BIND(Label, hint, "hint");
};

class Hints : public Box
{
  public:
    Hints();
    ~Hints();

    void setAddUnableAButtonAction(bool value)
    {
        addUnableAButtonAction = value;
    }

    bool getAddUnableAButtonAction() const
    {
        return addUnableAButtonAction;
    }

    void setAllowAButtonTouch(bool value)
    {
        allowAButtonTouch = value;
    }

    bool getAllowAButtonTouch() const
    {
        return allowAButtonTouch;
    }

    /*
     * Carried on the row rather than set on each hint, because the hints are
     * rebuilt from scratch every time focus or availability changes - anything
     * applied to a child is gone by the next rebuild.
     */
    void setHintFontSizes(float iconSize, float textSize);

    static View* create();

  private:
    void refillHints(View* focusView);
    bool addUnableAButtonAction = true;
    bool allowAButtonTouch      = false;
    bool forceShown             = false;
    float hintIconSize          = 0.0f;
    float hintTextSize          = 0.0f;

    VoidEvent::Subscription hintSubscription;
};

} // namespace brls
