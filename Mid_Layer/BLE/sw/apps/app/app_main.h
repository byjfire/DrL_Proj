/*************************************************************************************************/
/*!
 *  \file   app_main.h
 *
 *  \brief  Application framework main module.
 *
 *          $Date: 2017-05-24 18:03:34 -0500 (Wed, 24 May 2017) $
 *          $Revision: 12288 $
 *
 *  Copyright (c) 2011-2017 ARM Ltd., all rights reserved.
 *  ARM Ltd. confidential and proprietary.
 *
 *  IMPORTANT.  Your use of this file is governed by a Software License Agreement
 *  ("Agreement") that must be accepted in order to download or otherwise receive a
 *  copy of this file.  You may not use or copy this file for any purpose other than
 *  as described in the Agreement.  If you do not agree to all of the terms of the
 *  Agreement do not use this file and delete all copies in your possession or control;
 *  if you do not have a copy of the Agreement, you must contact ARM Ltd. prior
 *  to any use, copying or further distribution of this software.
 */
/*************************************************************************************************/
#ifndef APP_MAIN_H
#define APP_MAIN_H

#include "wsf_os.h"
#include "wsf_timer.h"
#include "dm_api.h"
#include "app_api.h"
#include "app_db.h"
#include "app_cfg.h"

#ifdef __cplusplus
extern "C" {
#endif


/**************************************************************************************************
  Macros
**************************************************************************************************/

/*! No security record handle  */
#define APP_DB_HDL_NONE             NULL

/*! Scanning mode types */
#define APP_SCAN_MODE_LEG           0     /*! Legacy scanning mode */
#define APP_SCAN_MODE_EXT           1     /*! Extended scanning mode */
#define APP_SCAN_MODE_NONE          255   /*! Unknown scanning mode */

/*! App WSF handler event bitmasks */
#define APP_BTN_DOWN_EVT            0x10  /*! Button pressed down event */

/*! App WSF message event starting values */
#define APP_MSG_START               0x00
#define APP_SLAVE_MSG_START         0x10
#define APP_MASTER_MSG_START        0x20

/*! App WSF message event enumeration */
enum
{
  APP_BTN_POLL_IND = APP_MSG_START,       /*! Button poll timer expired */
  APP_UI_TIMER_IND                        /*! UI timer expired */
};

/*! App slave WSF message event enumeration */
enum
{
  APP_CONN_UPDATE_TIMEOUT_IND = APP_SLAVE_MSG_START   /*! Connection parameter update timer expired */
};

/**************************************************************************************************
  Data Types
**************************************************************************************************/

/* Message handling function type */
typedef void (*appMsgHandler_t)(wsfMsgHdr_t *pMsg);

/* Advertising callback function type */
typedef void(*appAdvCback_t)(dmEvt_t *pMsg);

//passkey display callback
#define PASSKEY_DISPLAY       0x00   //display passkey
#define PASSKEY_PROMPT        0x01   /*! Prompt user to enter passkey */
#define CONFIRMVALUE_DISPLAY  0x02   //display Confirm Value
typedef void (*keydisp)(uint8_t event,uint32_t u32opt);

typedef struct
{
  appDevInfo_t      scanResults[APP_SCAN_RESULT_MAX];                       /*! Scan result storage */
  uint8_t           numScanResults;                                         /*! Number of scan results */
  uint8_t           idx;                                                    /*! Index of address being resolved in scan result list */
  appDbHdl_t        dbHdl;                                                  /*! Database record handle for address being resolved */
  bool_t            inProgress;                                             /*! TRUE if address resolution is in progress */
  uint8_t           scanMode;                                               /*! Scan and connect mode in use */
} appMasterCb_t;

/*! Slave control block */
typedef struct
{
  uint8_t           *pAdvData[DM_NUM_ADV_SETS][APP_NUM_DATA_LOCATIONS];     /*! Advertising data pointers */
  uint16_t          advDataLen[DM_NUM_ADV_SETS][APP_NUM_DATA_LOCATIONS];    /*! Advertising data lengths */
  uint16_t          advDataBufLen[DM_NUM_ADV_SETS][APP_NUM_DATA_LOCATIONS]; /*! Length of advertising data buffer maintained by Application */
  uint16_t          advDataOffset[DM_NUM_ADV_SETS][APP_NUM_DATA_LOCATIONS]; /*! Advertising data offsets */
  uint16_t          maxAdvDataLen[DM_NUM_ADV_SETS];                         /*! Maximum advertising data length supported by Controller */
  bool_t            bondable;                                               /*! TRUE if in bondable mode */
  bool_t            advDataSynced[DM_NUM_ADV_SETS];                         /*! TRUE if advertising/scan data is synced */
  uint8_t           advState[DM_NUM_ADV_SETS];                              /*! Advertising state */
  uint8_t           advType[DM_NUM_ADV_SETS];                               /*! Advertising type */
  bool_t            advTypeChanged[DM_NUM_ADV_SETS];                        /*! TRUE if advertising type is changed */
  uint8_t           discMode;                                               /*! Discoverable/connectable mode */
  bdAddr_t          peerAddr;                                               /*! Peer address */
  uint8_t           peerAddrType;                                           /*! Peer address type */
  bool_t            findLtk;                                                /*! TRUE if LTK request received while resolving address */
  appDbHdl_t        dbHdl;                                                  /*! Database record handle for address being resolved */
  bool_t            inProgress;                                             /*! TRUE if address resolution is in progress */
  appAdvCback_t     advStopCback;                                           /*! Advertising stopped callback */
  appAdvCback_t     advRestartCback;                                        /*! Advertising restart callback */
} appSlaveCb_t;

/*! Connection control block */
typedef struct
{
  appDbHdl_t        dbHdl;                                                  /*! Device database handle */
  dmConnId_t        connId;                                                 /*! Connection ID */
  bool_t            bonded;                                                 /*! TRUE if bonded with peer device */
  bool_t            bondByLtk;                                              /*! TRUE if bonded state being determined by LTK */
  bool_t            bondByPairing;                                          /*! TRUE if bonded state being determined by pairing */
  bool_t            initiatingSec;                                          /*! TRUE if initiating security */
  bool_t            setConnectable;                                         /*! TRUE if switching to connectable mode */
  bool_t            connWasIdle;                                            /*! TRUE if connection was idle at last check */
  uint8_t           rcvdKeys;                                               /*! Bitmask of keys received during pairing */
  uint8_t           attempts;                                               /*! Connection parameter update attempts */
  uint8_t           updateState;                                            /*! Connection Update State */
  wsfTimer_t        updateTimer;                                            /*! Connection parameter update timer */
} appConnCb_t;

/*! Main control block */
typedef struct
{
  appMsgHandler_t   slaveCback;                                             /*! Slave message handler callback */
  appMsgHandler_t   masterCback;                                            /*! Slave message handler callback */
} appCb_t;

/**************************************************************************************************
  Global Variables
**************************************************************************************************/

/*! Connection control block array */
extern appConnCb_t appConnCb[DM_CONN_MAX];

/*! WSF handler ID */
extern wsfHandlerId_t appHandlerId;

/*! Main control block */
extern appCb_t appCb;

/*! Master control block */
extern appMasterCb_t appMasterCb;

/*! Slave control block */
extern appSlaveCb_t appSlaveCb;

/**************************************************************************************************
  Function Declarations
**************************************************************************************************/

bool_t appCheckBonded(dmConnId_t connId);
bool_t appCheckBondByLtk(dmConnId_t connId);
uint8_t appNumConns(uint8_t role);

void appUiBtnPoll(void);
void appUiTimerExpired(wsfMsgHdr_t *pMsg);

/* slave utility functions */
extern void appSlaveResetAdvDataOffset(uint8_t advHandle);
extern void appAdvStart(uint8_t numSets, uint8_t *pAdvHandles, uint16_t *pInterval, uint16_t *pDuration,
                        uint8_t *pMaxEaEvents, bool_t cfgAdvParam);
extern void appAdvSetData(uint8_t advHandle, uint8_t location, uint16_t len, uint8_t *pData, uint16_t bufLen,
                          uint16_t maxLen);
extern void appSlaveAdvStart(uint8_t numSets, uint8_t *pAdvHandles, uint16_t *pInterval, uint16_t *pDuration,
                             uint8_t *pMaxEaEvents, bool_t cfgAdvParam, uint8_t mode);
extern void appAdvStop(uint8_t numSets, uint8_t *pAdvHandles);
extern bool_t appAdvSetAdValue(uint8_t advHandle, uint8_t location, uint8_t adType, uint8_t len,
                               uint8_t *pValue);
extern void appSetAdvType(uint8_t advHandle, uint8_t advType, uint16_t interval, uint16_t duration,
                          uint8_t maxEaEvents, bool_t cfgAdvParam);
extern void appConnAccept(uint8_t advHandle, uint8_t advType, uint16_t interval, uint16_t duration,
                          uint8_t maxEaEvents, uint8_t addrType, uint8_t *pAddr);

/* master utility functions */
extern dmConnId_t appConnOpen(uint8_t initPhys, uint8_t addrType, uint8_t *pAddr, appDbHdl_t dbHdl);

//**********************************************************************
// 函数功能: 设置UI 操作callback
// 输入参数：
// 返回参数：	
//**********************************************************************
void AppSetPasskeyDispCb(keydisp paction);

#ifdef __cplusplus
};
#endif

#endif /* APP_MAIN_H */
