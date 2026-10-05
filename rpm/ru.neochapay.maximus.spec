%define __provides_exclude_from ^%{_datadir}/%{name}/.*$
%define __requires_exclude ^lib.*\\.*$

Name:       ru.neochapay.maximus
Summary:    Клиент мессенджера MAX
Version:    0.0.11
Release:    4
License:    BSD-3-Clause
URL:        https://github.com/neochapay/ru.neochapay.maximus
Source0:    %{name}-%{version}.tar.bz2

Requires:   sailfishsilica-qt5
Requires:   nemo-qml-plugin-notifications-qt5
Requires:   qt5-qtgraphicaleffects
BuildRequires: pkgconfig(sailfishapp)
BuildRequires: pkgconfig(Qt5Core)
BuildRequires: pkgconfig(Qt5Gui)
BuildRequires: pkgconfig(Qt5Qml)
BuildRequires: pkgconfig(Qt5Quick)
BuildRequires: pkgconfig(Qt5Network)

%description
Нативный клиент MAX для Sailfish OS, портированный из проекта Maximus.

%prep
%autosetup

%build
%qmake5
%make_build

%install
%make_install

install -D -m 0644 src_sailfish/ru.neochapay.maximus.desktop \
    %{buildroot}%{_datadir}/applications/%{name}.desktop

for size in 86 108 128 172 256
do
    if [ -d "src_sailfish/icons/${size}x${size}" ]; then
        mkdir -p %{buildroot}%{_datadir}/icons/hicolor/${size}x${size}/apps
        cp -a src_sailfish/icons/${size}x${size}/* \
            %{buildroot}%{_datadir}/icons/hicolor/${size}x${size}/apps/
    fi
done

%files
%defattr(-,root,root,-)
%{_bindir}/%{name}
%{_datadir}/%{name}/
%{_datadir}/applications/%{name}.desktop
%{_datadir}/icons/hicolor/*/apps/*