;******************************************************************************
;
;! @file am_mcu_cmsis.s
;!
;! @brief Keil/ARM assembly definition for CMSIS.
;!
;! IMPORTANT: This EQU must be set to the same value as am_mcu_cmsis.h!
;!
;
;******************************************************************************

;******************************************************************************
;
; Copyright (c) 2018, Ambiq Micro
; All rights reserved.
; 
; Redistribution and use in source and binary forms, with or without
; modification, are permitted provided that the following conditions are met:
; 
; 1. Redistributions of source code must retain the above copyright notice,
; this list of conditions and the following disclaimer.
; 
; 2. Redistributions in binary form must reproduce the above copyright
; notice, this list of conditions and the following disclaimer in the
; documentation and/or other materials provided with the distribution.
; 
; 3. Neither the name of the copyright holder nor the names of its
; contributors may be used to endorse or promote products derived from this
; software without specific prior written permission.
; 
; Third party software included in this distribution is subject to the
; additional license terms as defined in the /docs/licenses directory.
; 
; THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
; AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
; IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
; ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
; LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
; CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
; SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
; INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
; CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
; ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
; POSSIBILITY OF SUCH DAMAGE.
;
; This is part of revision v1.2.12-837-gb0e09d712 of the AmbiqSuite Development Package.
;
;******************************************************************************

;******************************************************************************
;
; Set AM_CMSIS_REGS to 1 to use CMSIS-style register and vector access.
; Set AM_CMSIS_REGS to 0 to use AM_REG-style register and vector access.
;
; IMPORTANT: This value must be the same as the macro in am_mcu_cmsis.h!
;
;************************************************************************
AM_CMSIS_REGS   EQU     1

    END