/*
** ###################################################################
**
** Copyright 2025-2026 NXP
**
** Redistribution and use in source and binary forms, with or without modification,
** are permitted provided that the following conditions are met:
**
** o Redistributions of source code must retain the above copyright notice, this list
**   of conditions and the following disclaimer.
**
** o Redistributions in binary form must reproduce the above copyright notice, this
**   list of conditions and the following disclaimer in the documentation and/or
**   other materials provided with the distribution.
**
** o Neither the name of the copyright holder nor the names of its
**   contributors may be used to endorse or promote products derived from this
**   software without specific prior written permission.
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
** ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
** WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
** DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
** ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
** (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
** LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
** ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
** SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**
**
** ###################################################################
*/

/*==========================================================================*/
/* File containing the implementation of the PCA2131 RTC.                   */
/*==========================================================================*/

/* Note this code is an example. The conversion functions between date and
   seconds have not been fully tested to match The PCA2131 and calling
   agents. */

/* Includes */

#include "sm.h"
#include "brd_sm.h"
#include "lmm.h"

/* Local defines */

/* Local types */

/* Local variables */

/* Local functions */

/*--------------------------------------------------------------------------*/
/* Write RTC raw data                                                       */
/*--------------------------------------------------------------------------*/
int32_t BRD_SM_BbmRtcWrite(uint32_t addr, uint32_t numVal,
    const uint32_t *val)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check read size */
    if (numVal > 24U)
    {
        status = SM_ERR_INVALID_PARAMETERS;
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Read RTC raw data                                                        */
/*--------------------------------------------------------------------------*/
int32_t BRD_SM_BbmRtcRead(uint32_t addr, uint32_t numVal, uint32_t *val)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check read size */
    if (numVal > 24U)
    {
        status = SM_ERR_INVALID_PARAMETERS;
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Return RTC name                                                          */
/*--------------------------------------------------------------------------*/
int32_t BRD_SM_BbmRtcNameGet(uint32_t rtcId, string *rtcNameAddr,
    int32_t *len)
{
    int32_t status = SM_ERR_SUCCESS;
    static int32_t s_maxLen = 0;

    static string const s_name[BRD_SM_NUM_RTC] =
    {
        "pca2131"
    };

    /* Get max string width */
    DEV_SM_MaxStringGet(len, &s_maxLen, s_name, BRD_SM_NUM_RTC);

    if (rtcId < DEV_SM_NUM_RTC)
    {
        status = DEV_SM_BbmRtcNameGet(rtcId, rtcNameAddr, len);
    }
    else
    {
        /* gcov_excl_ntbr_nextline - range check above */
        if ((rtcId - DEV_SM_NUM_RTC) < BRD_SM_NUM_RTC)
        {
            /* Return pointer to name */
            *rtcNameAddr = s_name[rtcId - DEV_SM_NUM_RTC];
        }
        else
        {
            /* Set the status */
            status = SM_ERR_INVALID_PARAMETERS;  /* gcov_excl_line */
        }
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Return RTC info                                                          */
/*--------------------------------------------------------------------------*/
int32_t BRD_SM_BbmRtcDescribe(uint32_t rtcId, uint32_t *secWidth,
    uint32_t *tickWidth, uint32_t *ticksPerSec)
{
    int32_t status = SM_ERR_SUCCESS;

    if (rtcId < DEV_SM_NUM_RTC)
    {
        status = DEV_SM_BbmRtcDescribe(rtcId, secWidth, tickWidth,
            ticksPerSec);
    }
    else
    {
        /* Return RTC info */
        *secWidth = 32U;
        *tickWidth = 39U;
        *ticksPerSec = 100U;
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Set RTC time                                                             */
/*--------------------------------------------------------------------------*/
int32_t BRD_SM_BbmRtcTimeSet(uint32_t rtcId, uint64_t val, bool ticks)
{
    int32_t status = SM_ERR_SUCCESS;

    if (rtcId < DEV_SM_NUM_RTC)
    {
        status = DEV_SM_BbmRtcTimeSet(rtcId, val, ticks);
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Get RTC time                                                             */
/*--------------------------------------------------------------------------*/
int32_t BRD_SM_BbmRtcTimeGet(uint32_t rtcId, uint64_t *val, bool ticks)
{
    int32_t status = SM_ERR_SUCCESS;

    if (rtcId < DEV_SM_NUM_RTC)
    {
        status = DEV_SM_BbmRtcTimeGet(rtcId, val, ticks);
    }
    else
    {

        if (status == SM_ERR_SUCCESS)
        {
            /* Enable battery */
        }
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Get BBM RTC state                                                        */
/*--------------------------------------------------------------------------*/
int32_t BRD_SM_BbmRtcStateGet(uint32_t rtcId, uint32_t *state)
{
    int32_t status = SM_ERR_SUCCESS;

    if (rtcId < DEV_SM_NUM_RTC)
    {
        status = DEV_SM_BbmRtcStateGet(rtcId, state);
    }
    else
    {
        /* Default state */
        *state = 0U;
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Set RTC alarm                                                            */
/*--------------------------------------------------------------------------*/
int32_t BRD_SM_BbmRtcAlarmSet(uint32_t rtcId, bool enable, uint64_t val)
{
    int32_t status = SM_ERR_SUCCESS;

    if (rtcId < DEV_SM_NUM_RTC)
    {
        status = DEV_SM_BbmRtcAlarmSet(rtcId, enable, val);
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* PCA2131 interrupt handler                                                */
/*--------------------------------------------------------------------------*/
void BRD_SM_BbmHandler(void)
{
    /* Handle alarm */

    /* Clear status flags */
}


