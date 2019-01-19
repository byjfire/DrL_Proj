#ifndef H003_CONFIG_H
#define H003_CONFIG_H

#include "data_info.h"

/****************************************************************************************
**
**功能0: 定义项目编号和默认广播名
**
****************************************************************************************/
#define PROJECT_ID            "PE000"
#define SMOVT_ID               "H003"
#define SMOVT_ID_LEN           4
#define BLE_ADV_LOCALNAME_LEN  4
#define BLE_ADV_LOCALNAME      'H','0','0','3'

/****************************************************************************************
**
**功能1: 定义充电芯片类型
**
****************************************************************************************/
#define CHARGER_CE3150B   0    //H001
#define CHARGER_CW6304    1    //H002

#define CHARGER_CHIP      CHARGER_CW6304

/****************************************************************************************
**
**功能 2:使能MCU Burst Mode:设置为1，Apollo3设置为burst mode，clock可以跑到96Mhz
**       默认情况下clock是48Mhz
**
****************************************************************************************/
#define MCU_BURST_MODE_ENABLE         1

/****************************************************************************************
**
**功能 3:ANCS解析相关定义，新版消息详情
**
****************************************************************************************/
#define ANCS_VER_TYPE         ANCS_VER_2
#define ANCS_DETIL_TYPE       ANCS_DETIL_NEW

/****************************************************************************************
**
**功能: 定义OTA版本
**
****************************************************************************************/
#define APOLLO_OTA_TYPE  APOLLO_OTA_VER_2

#endif

