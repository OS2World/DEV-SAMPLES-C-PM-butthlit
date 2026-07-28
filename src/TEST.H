/*********************************************************************
 *                                                                   *
 * MODULE NAME :  test.h                                             *
 *                                                                   *
 * DESCRIPTION:                                                      *
 *                                                                   *
 *  Shared header for the Button Hilite test program.                *
 *  Defines resource IDs, the MSG_TYPE compatibility typedef, and    *
 *  the wpDlg prototype.                                             *
 *                                                                   *
 * HISTORY:                                                          *
 *                                                                   *
 *  1995-04-27  Wolf Dieter Biburger   Original version.             *
 *  2026-07-28  Martin Iturbide        Moved to src/, fixed include  *
 *                                     guard, updated docs.          *
 *                                                                   *
 *********************************************************************/

#ifndef TEST_H
#define TEST_H

/* In the 32-bit environment the second parameter of window
** procedures changed from USHORT to ULONG.
*/
typedef ULONG MSG_TYPE;

/* Dialog window procedure */
MRESULT EXPENTRY wpDlg( HWND hwnd, MSG_TYPE msg, MPARAM mp1, MPARAM mp2 );

/* Resource IDs */
#define ID_STATICS          0xffff
#define ID_DLG              4711
#define ID_LISTBOX          4712
#define ID_BUTT_1           4713
#define ID_BUTT_2           4714
#define ID_BUTT_3           4715
#define ID_BUTT_4           4716
#define ID_BUTT_5           4717

#define ID_MENU_1           4721
#define ID_MENU_2           4722
#define ID_MENU_3           4723
#define ID_MENU_4           4724
#define ID_MENU_5           4725

#endif /* TEST_H */
