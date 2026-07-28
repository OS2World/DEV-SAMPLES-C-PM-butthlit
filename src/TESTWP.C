/*********************************************************************
 *                                                                   *
 * MODULE NAME :  testwp.c                                           *
 *                                                                   *
 * DESCRIPTION:                                                      *
 *                                                                   *
 *  Dialog window procedure for the Button Hilite test program.      *
 *                                                                   *
 *  Handles only WM_INITDLG, WM_COMMAND, and WM_CLOSE; all other    *
 *  messages (including the button-highlight messages) are passed    *
 *  to WinDefDlgProc, which takes care of focus and highlight        *
 *  behaviour automatically.                                         *
 *                                                                   *
 * CALLABLE FUNCTIONS:                                               *
 *                                                                   *
 *  MRESULT EXPENTRY wpDlg( HWND hwnd, MSG_TYPE msg,                 *
 *                          MPARAM mp1, MPARAM mp2 )                  *
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
#include "test.h"

/**********************************************************************/
/*-------------------------------- wpDlg -----------------------------*/
/*                                                                   */
/*  MAIN DIALOG WINDOW PROCEDURE.                                    */
/*                                                                   */
/*  INPUT: dialog window handle,                                     */
/*         message id,                                               */
/*         message parameter 1,                                      */
/*         message parameter 2                                       */
/*                                                                   */
/*  WM_INITDLG - Load the menu resource and attach it to the dialog. */
/*  WM_COMMAND - Dispatch button/menu commands:                      */
/*               ID_MENU_1: sound a pair of error/note alarms.       */
/*               DID_OK:    (no action — placeholder).               */
/*               default:   delegate to WinDefDlgProc.               */
/*  WM_CLOSE / default - delegate to WinDefDlgProc.                  */
/*                                                                   */
/*  OUTPUT: message result (MRESULT)                                 */
/*                                                                   */
/*--------------------------------------------------------------------*/
/**********************************************************************/
MRESULT EXPENTRY wpDlg( HWND hwnd, MSG_TYPE msg, MPARAM mp1, MPARAM mp2 )
{
    MRESULT Result = (MRESULT) 0;

    switch( msg )
    {
    case WM_INITDLG:
        {
            HWND  hwndMenu;
            ULONG id;

            /* Load the menu, since it cannot be obtained via the
            ** dialog template alone at startup time.
            */
            id      = (ULONG) WinQueryWindowUShort( hwnd, QWS_ID );
            hwndMenu = WinLoadMenu( hwnd, (HMODULE) 0, id );
            (void) hwndMenu;
        }
        break;

    case WM_COMMAND:
        switch( LOUSHORT( mp1 ) )
        {
        case ID_MENU_1:
            WinAlarm( HWND_DESKTOP, WA_ERROR );
            WinAlarm( HWND_DESKTOP, WA_NOTE );
            WinAlarm( HWND_DESKTOP, WA_ERROR );
            WinAlarm( HWND_DESKTOP, WA_NOTE );
            break;

        case DID_OK:
            break;

        default:
            Result = WinDefDlgProc( hwnd, msg, mp1, mp2 );
            break;
        }
        break;

    case WM_CLOSE:
    default:
        Result = WinDefDlgProc( hwnd, msg, mp1, mp2 );
        break;
    }

    return Result;
}

/*************************************************************************
 *                     E N D     O F     S O U R C E                     *
 *************************************************************************/
