# Maximus Sailfish OS port

Target: Sailfish OS 5.1.0.11, Xperia XA2 (armv7hl).

This port intentionally uses the existing Qt5/Aurora Silica UI and the project's
bundled qtwebsockets5/qmaxmessenger libraries. The Qt6/Nemo implementation is
not used by the Sailfish Qt5 build.

Build with the Sailfish SDK:
  sfdk config --push target SailfishOS-5.1.0.11-armv7hl
  sfdk build

The resulting RPM is in RPMS/.
