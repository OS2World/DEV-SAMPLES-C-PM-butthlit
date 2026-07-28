# DEV-SAMPLES-C-PM-butthlit

OS/2 PM sample demonstrating the "Button Hilite Problem" solution using a
dialog-based main window instead of `WinCreateStdWindow`.

![butthlit ScreenShot](/wiki/butthlit.png)

## Description

`TEST.EXE` shows how `WinDefDlgProc` handles button-focus highlighting
automatically when the application's main window is a dialog. The program
loads a menu at `WM_INITDLG` time and uses `WinDlgBox` as its message loop,
avoiding the focus-management boilerplate that normally consumes most of a
PM programmer's time.

## Source structure

```
src/
  TESTMAIN.C   - PM initialisation, WinDlgBox entry point
  TESTWP.C     - dialog window procedure (wpDlg)
  TEST.H       - shared header: resource IDs, MSG_TYPE typedef, wpDlg prototype
  TEST.RC      - menu and dialog template resources
  test-gcc.def - GCC module definition (bldlevel, STACKSIZE)
  test-ow.lnk  - OpenWatcom wlink script
```

## Requirements

Install the following ArcaOS/OS/2 packages:

```
yum install git gcc make libc-devel binutils watcom-wrc watcom-wlink-hll
```

For OpenWatcom builds, install OpenWatcom 2.0 separately.

## Building with GCC 9.2

Run from the project root on the OS/2 system:

```
compile-gcc.cmd
```

The executable is placed in `bin-gcc\TEST.EXE`.  
The build log is saved to `compile-gcc.log`.

To clean: `compile-gcc.cmd clean`

## Building with OpenWatcom 2.0

```
compile-ow.cmd
```

The executable is placed in `bin-ow\TEST.EXE`.  
The build log is saved to `compile-ow.log`.

To clean: `compile-ow.cmd clean`

## Version history

| Version | Date       | Notes |
|---------|------------|-------|
| 1.01    | 2026-07-28 | Moved sources to `src/`, added dual GCC/OW build system, fixed include guard, updated docs. |
| 1.00    | 1995-04-27 | Original version by Wolf Dieter Biburger. |

## License

Not specified by original author.

## Authors

- Martin Iturbide (2026)
- Wolf Dieter Biburger (1995)

## Links

- Original source archive: https://archive.org/download/os2_94/os2_94.zip
