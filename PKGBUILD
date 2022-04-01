pkgname=pavutray
pkgver=0.1
pkgrel=1
arch=("x86_64")
makedepends=("cmake")
depends=("qt5-base")
url="https://github.com/git-fal7/sys-tray-pavucontrol"
source=("$pkgname::git+$url.git")
sha512sums=('SKIP')

build() {
	cd "sys-tray-pavucontrol"
	mkdir -p ../build
	cd ../build
	cmake .. -DCMAKE_INSTALL_PREFIX=/usr
	make
}

package() {
	cd ../build
	make DESTDIR="$pkgdir" install
}
