/*
 * Copyright (c) 2022 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
import Ability from '@ohos.app.ability.UIAbility'
import commonEvent from '@ohos.commonEvent';
import AcCtrl from '@ohos.abilityAccessCtrl'
let AcManager = AcCtrl.createAtManager()
var printLog1 = "Stage:MainAbility:";
var listPush1 = "Stage_MainAbility_";
var launchWant
var lastRequestWant
export default class MainAbility extends Ability {
    onCreate(want, launchParam) {
        console.info(printLog1 + "onCreate")
        AcManager.requestPermissionsFromUser(this.context, ['ohos.permission.DISTRIBUTED_DATASYNC'], function (result) {
            console.info('Calc[IndexPage] grantPermission,requestPermissionsFromUser')
        })
    }

    onDestroy() {
        console.info(printLog1 + "onDestroy")

        commonEvent.publish(listPush1 + "onDestroy", (err) => {
            console.info(printLog1 + listPush1 + "onDestroy");
        });
    }

    onWindowStageCreate(windowStage) {
        // Main window is created, set main page for this ability
        console.info(printLog1 + "onWindowStageCreate")

        windowStage.setUIContent(this.context, "pages/index", null)
    }

    onWindowStageDestroy() {
        // Main window is destroyed, release UI related resources
        console.info(printLog1 + "onWindowStageDestroy")
    }

    onForeground() {
        // Ability has brought to foreground
        console.info(printLog1 + "onForeground")
    }

    onBackground() {
        // Ability has back to background
        console.info(printLog1 + "onBackground")
    }

};
