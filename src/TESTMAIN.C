/*********************************************************************
 *                                                                   *
 * MODULE NAME :  testmain.c                                         *
 *                                                                   *
 * DESCRIPTION:                                                      *
 *                                                                   *
 *  Entry point for the Button Hilite test program.                  *
 *                                                                   *
 *  Instead of building a full WinCreateStdWindow frame, this        *
 *  program uses WinDlgBox to display the main dialog directly.      *
 *  This lets WinDefDlgProc handle all the tricky focus/button       *
 *  highlight behaviour automatically.                               *
 *                                                                   *
 * CALLABLE FUNCTIONS:                                               *
 *                                                                   *
 *  int main( int argc, char *argv[], char *envp[] )                 *
 *                                                                   *
 * HISTORY:                                                          *
 *                                                                   *
 *  1995-04-27  Wolf Dieter Biburger   Original version.             *
 *  2026-07-28  Martin Iturbide        Moved to src/, dual GCC/OW    *
 *                                     build system, updated docs.   *
 *                                                                   *
 *********************************************************************/

#define INCL_PM
#include <os2.h>
#include <stdio.h>
#include <stdlib.h>
#include "test.h"

/**********************************************************************/
/*-------------------------------- main ------------------------------*/
/*                                                                   */
/*  PROGRAM ENTRY POINT.                                             */
/*                                                                   */
/*  INPUT: command-line argc/argv/envp (not used)                    */
/*                                                                   */
/*  1. Initialize the PM anchor block and message queue.             */
/*  2. Display the main dialog via WinDlgBox.                        */
/*  3. Destroy the message queue and terminate PM.                   */
/*                                                                   */
/*  OUTPUT: 0 on success, -1 on failure                             */
/*                                                                   */
/*--------------------------------------------------------------------*/
/**********************************************************************/
int main( int argc, char *argv[], char *envp[] )
{
    int   Ret = -1;
    ULONG ulDlgResult;
    HAB   hab;
    HMQ   hmq;

    (void) argc;
    (void) envp;

    while( 1 )
    {
        hab = WinInitialize( 0 );
        if( hab == (HAB) 0 )
        {
            fprintf( stderr, "%s: got no HAB!\n", argv[0] );
            break;
        }

        hmq = WinCreateMsgQueue( hab, (LONG) 10240 );
        if( hmq == (HMQ) 0 )
        {
            fprintf( stderr, "%s: got no HMQ!\n", argv[0] );
            WinTerminate( hab );
            break;
        }

        ulDlgResult = WinDlgBox(
            HWND_DESKTOP, HWND_DESKTOP,
            wpDlg,
            (HMODULE) 0,
            (ULONG) ID_DLG,
            (PVOID) 0 );

        WinDestroyMsgQueue( hmq );
        WinTerminate( hab );

        Ret = 0;
        break;
    }

    (void) ulDlgResult;
    return Ret;
}

/*************************************************************************
 *                     E N D     O F     S O U R C E                     *
 *************************************************************************/
