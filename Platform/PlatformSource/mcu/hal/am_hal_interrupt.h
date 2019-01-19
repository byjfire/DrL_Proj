//*****************************************************************************
//
//  am_hal_interrupt.h
//! @file
//!
//! @brief Helper functions supporting interrupts and NVIC operation.
//!
//! These functions may be used for NVIC-level interrupt configuration.
//!
//! @addtogroup interrupt3 Interrupt (ARM NVIC support functions)
//! @ingroup apollo3hal
//! @{
//
//*****************************************************************************

//*****************************************************************************
//
// Copyright (c) 2018, Ambiq Micro
// All rights reserved.
// 
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
// 
// 1. Redistributions of source code must retain the above copyright notice,
// this list of conditions and the following disclaimer.
// 
// 2. Redistributions in binary form must reproduce the above copyright
// notice, this list of conditions and the following disclaimer in the
// documentation and/or other materials provided with the distribution.
// 
// 3. Neither the name of the copyright holder nor the names of its
// contributors may be used to endorse or promote products derived from this
// software without specific prior written permission.
// 
// Third party software included in this distribution is subject to the
// additional license terms as defined in the /docs/licenses directory.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
//
// This is part of revision v1.2.12-837-gb0e09d712 of the AmbiqSuite Development Package.
//
//*****************************************************************************
#ifndef AM_HAL_INTERRUPT_H
#define AM_HAL_INTERRUPT_H

#ifdef __cplusplus
extern "C"
{
#endif

#if !AM_CMSIS_REGS
//*****************************************************************************
//
//! @name ISR number macros.
//! @brief ISR macros.
//!
//! These macros are used for all ui32Interrupt arguments in this module.
//! @{
//
//*****************************************************************************
//
// Hardware interrupts
//
#define AM_HAL_INTERRUPT_MAX                (51)    //AM_HAL_INTERRUPT_SOFTWARE3
#define AM_HAL_INTERRUPT_RESET              1
#define AM_HAL_INTERRUPT_NMI                2
#define AM_HAL_INTERRUPT_HARDFAULT          3
#define AM_HAL_INTERRUPT_MPUFAULT           4
#define AM_HAL_INTERRUPT_BUSFAULT           5
#define AM_HAL_INTERRUPT_USAGEFAULT         6

#define AM_HAL_INTERRUPT_SVCALL             11
#define AM_HAL_INTERRUPT_DEBUGMON           12
#define AM_HAL_INTERRUPT_PENDSV             14
#define AM_HAL_INTERRUPT_SYSTICK            15

//
// Begin IRQs
//
#define AM_HAL_INTERRUPT_BROWNOUT           16
#define AM_HAL_INTERRUPT_WATCHDOG           17
#define AM_HAL_INTERRUPT_RTC                18
#define AM_HAL_INTERRUPT_VCOMP              19
#define AM_HAL_INTERRUPT_IOSLAVE            20
#define AM_HAL_INTERRUPT_IOSACC             21
#define AM_HAL_INTERRUPT_IOMASTER0          22
#define AM_HAL_INTERRUPT_IOMASTER1          23
#define AM_HAL_INTERRUPT_IOMASTER2          24
#define AM_HAL_INTERRUPT_IOMASTER3          25
#define AM_HAL_INTERRUPT_IOMASTER4          26
#define AM_HAL_INTERRUPT_IOMASTER5          27
#define AM_HAL_INTERRUPT_BLE                28
#define AM_HAL_INTERRUPT_GPIO               29
#define AM_HAL_INTERRUPT_CTIMER             30
#define AM_HAL_INTERRUPT_UART0              31
#define AM_HAL_INTERRUPT_UART1              32
#define AM_HAL_INTERRUPT_UART               (AM_HAL_INTERRUPT_UART0)
#define AM_HAL_INTERRUPT_SCARD              33
#define AM_HAL_INTERRUPT_ADC                34
#define AM_HAL_INTERRUPT_PDM                35
#define AM_HAL_INTERRUPT_MSPI               36
#define AM_HAL_INTERRUPT_RESERVED0          37
#define AM_HAL_INTERRUPT_STIMER             38
#define AM_HAL_INTERRUPT_STIMER_CMPR0       39
#define AM_HAL_INTERRUPT_STIMER_CMPR1       40
#define AM_HAL_INTERRUPT_STIMER_CMPR2       41
#define AM_HAL_INTERRUPT_STIMER_CMPR3       42
#define AM_HAL_INTERRUPT_STIMER_CMPR4       43
#define AM_HAL_INTERRUPT_STIMER_CMPR5       44
#define AM_HAL_INTERRUPT_STIMER_CMPR6       45
#define AM_HAL_INTERRUPT_STIMER_CMPR7       46
#define AM_HAL_INTERRUPT_CLKGEN             47

#define AM_HAL_INTERRUPT_SOFTWARE0          48
#define AM_HAL_INTERRUPT_SOFTWARE1          49
#define AM_HAL_INTERRUPT_SOFTWARE2          50
#define AM_HAL_INTERRUPT_SOFTWARE3          51
//! @}

//*****************************************************************************
//
//! @brief Interrupt priority
//!
//! This macro is made to be used with the \e am_hal_interrupt_priority_set()
//! function. It converts a priority number to the format used by the ARM
//! standard priority register, where only the top 3 bits are used.
//!
//! For example, AM_HAL_INTERRUPT_PRIORITY(1) yields a value of 0x20.
//
//*****************************************************************************
#define AM_HAL_INTERRUPT_PRIORITY(n)        (((uint32_t)(n) & 0x7) << 5)

//*****************************************************************************
//
// External function definitions
//
//*****************************************************************************
extern void am_hal_interrupt_enable(uint32_t ui32Interrupt);
extern void am_hal_interrupt_disable(uint32_t ui32Interrupt);
extern void am_hal_interrupt_pend_set(uint32_t ui32Interrupt);
extern void am_hal_interrupt_pend_clear(uint32_t ui32Interrupt);
extern void am_hal_interrupt_priority_set(uint32_t ui32Interrupt,
                                          uint32_t ui32Priority);
#endif // AM_CMSIS_REGS

extern uint32_t am_hal_interrupt_master_disable(void);
extern uint32_t am_hal_interrupt_master_enable(void);
extern void am_hal_interrupt_master_set(uint32_t ui32InterruptState);

#ifdef __cplusplus
}
#endif

#endif // AM_HAL_INTERRUPT_H

//*****************************************************************************
//
// End Doxygen group.
//! @}
//
//*****************************************************************************