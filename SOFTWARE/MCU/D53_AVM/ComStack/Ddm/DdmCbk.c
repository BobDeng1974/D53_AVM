/*  BEGIN_FILE_HDR
************************************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information contained in this
*   doc should not be reproduced, or used, or disclosed without the written authorization from
*   HiRain Technologies.
************************************************************************************************
*   File Name       : DDMCbk.c
************************************************************************************************
*   Project/Product : System module
*   Title           : 
*   Author          : rui.guo
************************************************************************************************
*   Description     : This module ...
*
************************************************************************************************
*   Limitations     : 
************************************************************************************************
*
************************************************************************************************
*   Revision History:
*
*    Version      Date          Initials      CR#          Descriptions
*   ---------   ----------    ------------  ----------  ---------------
*     1.0        2015/03/15      rui.guo        N/A          Original
*     1.1        2015/09/29      rui.guo        N/A          
************************************************************************************************
* END_FILE_HDR*/

/*******************************************************************

1��ÿ��DTC����Ӧһ���ṹ�����ݣ�����ṹ�������DTC״̬��Ϣ,���£�
typedef struct
{
    uint8  ucDTCCurStatus;
    uint8  ucDTCLastStatus;
    uint16 usAgingCounter;
    sint16 ssFCounterSequential;
    sint16 ssFCounterIntermit;
    uint8  ucSwitchInter;
}DTCStatusInfoType;
��DTC״̬�ı�ʱ�����緢������DDM�ͻ����Cbk_DDMSaveDTCStatus��������һ�δ洢����ṹ��Ĳ���,
��Cbk_DDMSaveDTCStatus�����е���EEP��صĺ���������д��EEP.
��ϸ�뿴Cbk_DDMSaveDTCStatus�е�ע�͡�

2������Cbk_DDMRestoreDTCStatus���ڳ�ʼ���׶δ�EEP�ж�ȡDTC״̬��Ϣ��
��ϸ�뿴Cbk_DDMRestoreDTCStatus�е�ע�͡�

3��Ӧ�ó�����Ϊÿ��DTC����һ��ռ����ڴ洢DTC״̬��Ϣ����ַ�ռ������Ӧ�ó��������
************************************************************************/
#include "Ddm.h"

/* BEGIN_FUNCTION_HDR
************************************************************************************************
* Function Name : NONE
*
* Description   : NONE
*
* Arguments     : NONE
* 
* Returns       : NONE
*
* Limitations   : NONE
*                 
************************************************************************************************
END_FUNCTION_HDR */

Std_ReturnType Cbk_DDMRestoreDTCStatus(uint16 dtcindex,DTCStatusInfoType* buff,uint16 cnt)
{
    Std_ReturnType ret = E_OK;
    /*��dtcindex 0xffffʱ����ʾһ���Իָ�����dtc״̬*/
    
    /*�״��ϵ���Ϊ������Ч ���ж������Ƿ���Ч�ķ�����Ӧ�ó����Լ�������
      ����EEP����ȫFF������������Ч��־(Ҳ�����EEP)*/
    /*if(DTC������Ч)*/  
    {
        ret = E_NOT_OK;
    }
    //else 
    {
        /*��ʼ �������ݣ�����������̳��ִ��󷵻� E_NOT_OK*/
        ret = E_NOT_OK;
    }


    return ret;
}
/* BEGIN_FUNCTION_HDR
************************************************************************************************
* Function Name : NONE
*
* Description   : NONE
*
* Arguments     : NONE
* 
* Returns       : NONE
*
* Limitations   : NONE
*                 
************************************************************************************************
END_FUNCTION_HDR */

void Cbk_DTCM_StoreFreezeFrame
(
#ifdef DDM_FIRST_STORE_FREEZEFRAME_INDI 
uint8 firstFlag,
#endif
uint16 dtcIndex
)
{
/*�洢���ջ���չ����*/

}
/* BEGIN_FUNCTION_HDR
************************************************************************************************
* Function Name : NONE
*
* Description   : NONE
*
* Arguments     : NONE
* 
* Returns       : NONE
*
* Limitations   : NONE
*                 
************************************************************************************************
END_FUNCTION_HDR */
Std_ReturnType Cbk_DDMSaveAllDTCStatusRequest(uint8* dat,uint16 len)
{
    /*Tip: �ڴ˺����е���д��Dflash��д��ӿ�End*/

     
    /*!!!!!!!���뽫���ݿ���������ȫ��buffer��!!!!!*/
    
    Std_ReturnType ucRet = DDM_OK;
    
    /*
    ����ֵ˵��:
    DDM_OK:        �����������
    DDM_NOT_OK:������󱻾ܣ��Ҳ���Ҫ�ٴ�����
    DDM_CLRDTCBUSY:���������ʱ���ܽ��ܣ����ٴ�����
     */

    return ucRet;
}
Std_ReturnType Cbk_DDMRequireDTCSaveReault(void)
{
    /*Tip: �ڴ˺����е��ò�ѯDflash��д�����ĺ���End*/


    Std_ReturnType ucRet = DDM_OK;

    /*
    DDM_OK:        ������
    DDM_CLRDTCBUSY:���δ��ɣ�����Ҫ�ٴβ�ѯ
    ����: ���ʧ��
     */

    return ucRet;
}

/* BEGIN_FUNCTION_HDR
************************************************************************************************
* Function Name : NONE
*
* Description   : NONE
*
* Arguments     : NONE
* 
* Returns       : NONE
*
* Limitations   : NONE
*                 
************************************************************************************************
END_FUNCTION_HDR */
#if 0

Std_ReturnType Cbk_DDMSaveDTCStatus(uint16 DTCIndex,DTCStatusInfoType* StPtr,uint16 cnt)
{
/*
    �˺������ڴ洢��ǰDTC��״̬��Ϣ��
    index�ǵ�ǰ��ҪDTC�����ţ�StPtr����Ҫ�洢������ָ�룬cnt����Ҫ�洢�����ݳ���

    Ӧ�ó�������index�ҵ���Ӧ��EEP��ַ����StPtrָ������ݴ洢��EEP���洢�ɹ�����E_OK.���򷵻�E_NOT_OK

*/
    Std_ReturnType ucRet = E_OK;

    return ucRet;

}
/* BEGIN_FUNCTION_HDR
************************************************************************************************
* Function Name : NONE
*
* Description   : NONE
*
* Arguments     : NONE
* 
* Returns       : NONE
*
* Limitations   : NONE
*                 
************************************************************************************************
END_FUNCTION_HDR */

Std_ReturnType Cbk_DDMClrDTCDataSaveStatus(uint8* buff,uint16 cnt)
{
    Std_ReturnType ucRet = E_OK;

    return ucRet;
}
#endif
/* BEGIN_FUNCTION_HDR
************************************************************************************************
* Function Name : NONE
*
* Description   : NONE
*
* Arguments     : NONE
* 
* Returns       : NONE
*
* Limitations   : NONE
*                 
************************************************************************************************
END_FUNCTION_HDR */

Std_ReturnType Cbk_DDMReqSnapshotByDID(DTCRecdNumInfoType* pDtcRecd)
{
    Std_ReturnType ucRet = E_OK;

    return ucRet;
}
/* BEGIN_FUNCTION_HDR
************************************************************************************************
* Function Name : NONE
*
* Description   : NONE
*
* Arguments     : NONE
* 
* Returns       : NONE
*
* Limitations   : NONE
*                 
************************************************************************************************
END_FUNCTION_HDR */
Std_ReturnType Cbk_DDMReqExtendedDataByRecdNum(uint16 dtcidx,uint8 recd,uint8* data,uint16 len)
{
    Std_ReturnType ucRet = E_OK;
#ifdef DDM_FAULT_OCCURCOUNTER_RECORD
    *data = DDMGetFaultOccurCounter(dtcidx);
#endif
#ifdef DDM_FAULT_PENDINGCOUNTER_SUPPORT
    *(data+1) = DDMGetFaultPendingCounter(dtcidx);
#endif
#ifdef DDM_AGAED_COUNTER_RECORD
    *(data+2) = DDMGetAgedCounter(dtcidx);
#endif
    *(data+3) = DDMGetAgingCounter(dtcidx);
    
    return ucRet;
}
/* BEGIN_FUNCTION_HDR
************************************************************************************************
* Function Name : NONE
*
* Description   : NONE
*
* Arguments     : NONE
* 
* Returns       : NONE
*
* Limitations   : NONE
*                 
************************************************************************************************
END_FUNCTION_HDR */

Std_ReturnType Cbk_DDMTestReseultFailPre(uint16 usDtcIndex)
{
    /*ʵ��DTC����֮�������Ӧ���߼�*/
    /*���� 0 ��ʾ����������ã������ֹ���ã����������߼����ƣ���Ȼ����������������Ҳ��������*/
    Std_ReturnType ucRet = E_OK;
    uint8 BitMask = 0;

    if(usDtcIndex<NUMBER_OF_DTC)
    {
        BitMask = DDMGetCurrentStatusByMask(usDtcIndex,DTC_STATUS_BIT0_TEST_FAILED);
        if(0 != BitMask)
        {  /*��ǰBit0==1�������Ѿ�����¼������Ҫ�ټ�¼��*/
            ucRet = E_NOT_OK;
        }
        else
        {/*��ǰBit0==0��������Ҫ��¼DTC*/
            
        }
    }
    else
    {
        ucRet = E_NOT_OK;
    }
    return ucRet;
}
/* BEGIN_FUNCTION_HDR
************************************************************************************************
* Function Name : NONE
*
* Description   : NONE
*
* Arguments     : NONE
* 
* Returns       : NONE
*
* Limitations   : NONE
*                 
************************************************************************************************
END_FUNCTION_HDR */

Std_ReturnType Cbk_DDMTestReseultPassPre(uint16 usDtcIndex)
{
    /*ʵ��DTC����֮�������Ӧ���߼�*/
    /*���� 0 ��ʾ����������ã������ֹ���ã����������߼����ƣ���Ȼ����������������Ҳ��������*/
    Std_ReturnType ucRet = E_OK;
    uint8 BitMask = 0;
       
    if(usDtcIndex < NUMBER_OF_DTC)
    {
    
        BitMask = DDMGetCurrentStatusByMask(usDtcIndex,(DTC_STATUS_BIT0_TEST_FAILED|DTC_STATUS_BIT4_NO_TEST_CLEARED|DTC_STATUS_BIT6_NO_TEST_THIS_CYCLE));
        if(0 == BitMask)
        {   /*��һ�β���ͨ�������Ѿ�����¼������Ҫ�ټ�¼��*/
            ucRet = E_NOT_OK;
        }
        else
        {/*��ǰBit0==0��������Ҫ��¼DTC*/
            
        }
    }
    else
    {
        ucRet = E_NOT_OK;
    }

    return ucRet;
}


void Cbk_DDMEventFiltered(uint16 usDTCIndex, uint8 ucCurrentState)
{

}

/********************************End*******************************************/

