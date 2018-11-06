/*
|NOTICE
|-------------------------------------------------------------------------------
|                              
|   This software is the property of GUANGDA Technologies. 
|
|END----------------------------------------------------------------------------
|FILE INFORMATION START
|-------------------------------------------------------------------------------
|     File Name: 
|   Description: Implementation of the CAN driver
|Target systems: RRS
|    Target CPU: upd78F1828
|           IDE: CS+ V20200                           
|      Compiler: CC78k0r
|END----------------------------------------------------------------------------
|PROJECT INFORMATION START 
|-------------------------------------------------------------------------------
| Project Name: 
|
|  Description: 
|
|END----------------------------------------------------------------------------
|REVISION HISTORY
|-------------------------------------------------------------------------------
| Version        Date          Author              Description
| --------   -----------      ---------     ------------------------------------
| 00.01.00    2015-08-04                             first version
|-------------------------------------------------------------------------------
*/
#include "control.h"
#include "NmTypes.h"
#include "NmCfg.h"
#include "Com.h"
#include "CanTp.h"
#include "Dcm.h"
#include "Ddm.h"

extern void Can_PortInit(void);
/*******************************************************************************
* Function Name     : 
* Returned Value    :
* Parameters(Input) :
* Parameters(Output):
* Comments          :
*   This function ....
*
*
*******************************************************************************/
void App_IndirNmStartUp(void)
{
    /* start the  Can communication */
    /*Init Can communication*/
    Can_PortInit();
    Can_Init(); 
    CanIf_Init();
    CanIf_SetControllerMode(0,CANIF_CS_STARTED);
    Com_Init();
    Com_RxStart();
    Com_TxStart();
    CanTp_Init(&CanTp_Cfg);
    Dcm_Init((void*)0);

    //DDMInit(); �ŵ������ط�������ʼ��
    //DDMSetOperationMode(DDM_STARTCYCLE);�ŵ������ط�������ʼ��

}
/*******************************************************************************
* Function Name     : 
* Returned Value    :
* Parameters(Input) :
* Parameters(Output):
* Comments          :
*   This function ....
*
*
*******************************************************************************/

void App_IndirNmShutDownSyn(void)
{
    IndirNmGlobalIntDisable();
    /*��ѡ��: com�շ���ֹ*/
    Com_RxStop();
    Com_TxStop();

    IndirNmGlobalIntEnable();
}


void App_IndirNmShutDownPost(void)/*�ӳ�n��������ֹͣCAN��������ֹ���������֡*/
{
    IndirNmGlobalIntDisable();
    
    /*��ѡ��: CAN��������ֹ*/
    CanIf_SetControllerMode(0,CANIF_CS_STOPPED);

    /*��ѡ��: CAN�շ�����ֹ*/

    IndirNmGlobalIntEnable();
}

/*******************************************************************************
* Function Name     : 
* Returned Value    :
* Parameters(Input) :
* Parameters(Output):
* Comments          :
*   This function ....
*
*
*******************************************************************************/

void Appl_IndirNmRecoverSuccess(void)
{
	Ctl_EnableNetworkDiagnostic();
}
/*******************************************************************************
* Function Name     : 
* Returned Value    :
* Parameters(Input) :
* Parameters(Output):
* Comments          :
*   This function ....
*
*
*******************************************************************************/

void Appl_IndirNmReachMaxTimes(void)
{
    /*Bus Off recovery failed */
   /*Add App code here*/
}
/*******************************************************************************
* Function Name     : 
* Returned Value    :
* Parameters(Input) :
* Parameters(Output):
* Comments          :
*   This function ....
*
*
*******************************************************************************/

void Appl_IndirNmBusOffStart(void)
{
    /*Stop Com Tx (and Rx)*/
    Com_TxStop();
    Com_RxStop();
    /*inform DDM*/
    DDMTestPreResultProcess(DTC_BUSOFF_INDEX,DTC_TEST_PREFAILED);
    Ctl_DisableNetworkDiagnostic();
}
/*******************************************************************************
* Function Name     : 
* Returned Value    :
* Parameters(Input) :
* Parameters(Output):
* Comments          :
*   This function ....
*
*
*******************************************************************************/

void Appl_IndirNmBusOffEnd(void)
{
    /*Start Com Tx (and Rx)*/
    Com_TxStart();
    Com_RxStart();
}


