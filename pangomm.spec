%define apiver 1.4
# first two digits of version
%define release_version %(echo %{version} | awk -F. '{print $1"."$2}')

%global glibmm_version 2.48.0
%global cairomm_version 1.2.2
%global pango_version 1.38.0

Name:           pangomm
Version:        2.40.1
Release:        1%{?dist}
Summary:        C++ interface for Pango

Group:          System Environment/Libraries
License:        LGPLv2+
URL:            http://www.gtkmm.org/
Source0:        http://ftp.gnome.org/pub/GNOME/sources/pangomm/%{release_version}/%{name}-%{version}.tar.xz

BuildRequires:  glibmm24-devel >= %{glibmm_version}
BuildRequires:  cairomm-devel >= %{cairomm_version}
BuildRequires:  pango-devel >= %{pango_version}
BuildRequires:  doxygen graphviz

Requires:       glibmm24%{?_isa} >= %{glibmm_version}
Requires:       cairomm%{?_isa} >= %{cairomm_version}
Requires:       pango%{?_isa} >= %{pango_version}

%description
pangomm provides a C++ interface to the Pango library. Highlights
include typesafe callbacks, widgets extensible via inheritance and a
comprehensive set of widget classes that can be freely combined to
quickly create complex user interfaces.


%package devel
Summary:        Headers for developing programs that will use %{name}
Group:          Development/Libraries
Requires:       %{name}%{?_isa} = %{version}-%{release}

%description devel
This package contains the libraries and header files needed for
developing pangomm applications.


%package          doc
Summary:          Developer's documentation for the pangomm library
Group:            Documentation
BuildArch:        noarch
Requires:         %{name} = %{version}-%{release}
Requires:         libsigc++20-doc
Requires:         glibmm24-doc

%description      doc
This package contains developer's documentation for the pangomm
library. Pangomm is the C++ API for the Pango font layout library.

The documentation can be viewed either through the devhelp
documentation browser or through a web browser.

%prep
%setup -q


%build
%configure --disable-static
make %{?_smp_mflags}


%install
%make_install

find $RPM_BUILD_ROOT -type f -name "*.la" -exec rm -f {} ';'


%post -p /sbin/ldconfig


%postun -p /sbin/ldconfig


%files
%license COPYING
%doc AUTHORS NEWS README
%{_libdir}/*.so.*


%files devel
%{_includedir}/pangomm-%{apiver}
%{_libdir}/*.so
%{_libdir}/pkgconfig/*.pc
%{_libdir}/pangomm-%{apiver}

%files doc
%doc %{_docdir}/pangomm-%{apiver}/
%{_datadir}/devhelp/

%changelog
* Sun Aug 21 2016 Kalev Lember <klember@redhat.com> - 2.40.1-1
- Update to 2.40.1
- Resolves: #1387033

* Fri Jan 24 2014 Daniel Mach <dmach@redhat.com> - 2.34.0-3
- Mass rebuild 2014-01-24

* Fri Dec 27 2013 Daniel Mach <dmach@redhat.com> - 2.34.0-2
- Mass rebuild 2013-12-27

* Mon Apr 29 2013 Kalev Lember <kalevlember@gmail.com> - 2.34.0-1
- Update to 2.34.0

* Thu Feb 14 2013 Fedora Release Engineering <rel-eng@lists.fedoraproject.org> - 2.28.4-3
- Rebuilt for https://fedoraproject.org/wiki/Fedora_19_Mass_Rebuild

* Fri Jul 20 2012 Fedora Release Engineering <rel-eng@lists.fedoraproject.org> - 2.28.4-2
- Rebuilt for https://fedoraproject.org/wiki/Fedora_18_Mass_Rebuild

* Mon Feb 27 2012 Kalev Lember <kalevlember@gmail.com> - 2.28.4-1
- Update to 2.28.4

* Fri Jan 13 2012 Fedora Release Engineering <rel-eng@lists.fedoraproject.org> - 2.28.3-2
- Rebuilt for https://fedoraproject.org/wiki/Fedora_17_Mass_Rebuild

* Tue Sep 27 2011 Ray <rstrode@redhat.com> - 2.28.3-1
- Update to 2.28.3

* Thu Mar 31 2011 Kalev Lember <kalev@smartlink.ee> - 2.28.2-1
- Update to 2.28.2

* Fri Mar 25 2011 Kalev Lember <kalev@smartlink.ee> - 2.28.1-1
- Update to 2.28.1
- Removed old obsoletes for gtkmm24

* Wed Mar 02 2011 Kalev Lember <kalev@smartlink.ee> - 2.27.1-3
- Own /usr/share/doc/pangomm-1.4/ dir
- Require base package from -doc subpackage

* Mon Feb 21 2011 Haïkel Guémar <hguemar@fedoraproject.org> - 2.27.1-2
- split doc into subpackage
- fix documentation location
- co-own /usr/share/devhelp

* Tue Feb 08 2011 Fedora Release Engineering <rel-eng@lists.fedoraproject.org> - 2.27.1-2
- Rebuilt for https://fedoraproject.org/wiki/Fedora_15_Mass_Rebuild

* Thu Jan 13 2011 Kalev Lember <kalev@smartlink.ee> - 2.27.1-1
- Update to 2.27.1
- Use macro for figuring out first two digits of version

* Wed Sep 29 2010 jkeating - 2.26.2-3
- Rebuilt for gcc bug 634757

* Tue Sep 14 2010 Kalev Lember <kalev@smartlink.ee> - 2.26.2-2
- Co-own /usr/share/gtk-doc/ directory (#604407)
- Dropped pkgconfig dep from -devel subpackage which is now automatically added

* Mon Jul 05 2010 Kalev Lember <kalev@smartlink.ee> - 2.26.2-1
- Update to 2.26.2

* Tue Apr 13 2010 Haïkel Guémar <hguemar@fedoraproject.org> -2.26.0-2
- Rebuilt for F-13

* Fri Sep 25 2009 Denis Leroy <denis@poolshark.org> - 2.26.0-1
- Update to upstream 2.26.0

* Mon Sep 14 2009 Denis Leroy <denis@poolshark.org> - 2.25.1.3-1
- Update to upstream 2.25.1.3
- Package pangomm libdir directory with config include header
- Fix documentation location

* Sat Jul 25 2009 Fedora Release Engineering <rel-eng@lists.fedoraproject.org> - 2.24.0-2
- Rebuilt for https://fedoraproject.org/wiki/Fedora_12_Mass_Rebuild

* Wed Apr  1 2009 Denis Leroy <denis@poolshark.org> - 2.24.0-1
- Update to upstream 2.24.0

* Thu Feb 26 2009 Fedora Release Engineering <rel-eng@lists.fedoraproject.org> - 2.14.1-2
- Rebuilt for https://fedoraproject.org/wiki/Fedora_11_Mass_Rebuild

* Wed Nov 26 2008 Denis Leroy <denis@poolshark.org> - 2.14.1-1
- Update to 2.14.1
- Devhelp patch upstreamed

* Sun Oct 12 2008 Denis Leroy <denis@poolshark.org> - 2.14.0-2
- Added patch to fix devhelp main page

* Tue Sep 23 2008 Denis Leroy <denis@poolshark.org> - 2.14.0-1
- Update to stable 2.14.0

* Fri Aug 29 2008 Denis Leroy <denis@poolshark.org> - 2.13.7-3
- Obsoletes older gtkmm to avoid libpangomm conflict 

* Wed Aug 27 2008 Denis Leroy <denis@poolshark.org> - 2.13.7-2
- Spec review fixes

* Mon Aug 25 2008 Denis Leroy <denis@poolshark.org> - 2.13.7-1
- First version
