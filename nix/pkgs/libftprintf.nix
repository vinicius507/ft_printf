{
  lib,
  stdenv,
  libftPath,
}:
stdenv.mkDerivation {
  pname = "libftprintf";
  version = "1.0.0";
  src = ../../ft_printf;
  buildPhase = ''
    export LIBFT_PATH="${libftPath}"
    make
  '';
  installPhase = ''
    mkdir -p $out/lib
    cp libftprintf.a $out/lib
    cp -r include $out/include
  '';
  meta = with lib; {
    license = licenses.agpl3Only;
  };
}
