{
  inputs = {
    nixpkgs.url = "nixpkgs";
    ft-nix = {
      url = "github:vinicius507/42-nix";
      inputs.nixpkgs.follows = "nixpkgs";
    };
    libft = {
      url = "github:vinicius507/libft";
      inputs.nixpkgs.follows = "nixpkgs";
    };
  };
  outputs = {
    self,
    nixpkgs,
    ft-nix,
    libft,
  }: let
    allSystems = [
      "x86_64-linux"
      "aarch64-linux"
    ];
    forEachSystem = f:
      nixpkgs.lib.genAttrs allSystems (system:
        f {
          pkgs = import nixpkgs {
            inherit system;
            overlays = [ft-nix.overlays.norminette];
          };
        });
  in {
    checks = forEachSystem ({pkgs}: {
      norminette-check = pkgs.stdenvNoCC.mkDerivation {
        name = "norminette-check";
        src = ./ft_printf;
        dontBuild = true;
        doCheck = true;
        checkPhase = with pkgs; ''
          ${norminette}/bin/norminette $src
        '';
        installPhase = "touch $out"; # Derivation must build an output.
      };
    });
    packages = forEachSystem ({pkgs}: {
      default = self.packages.${pkgs.system}.libftprintf;
      libftprintf = pkgs.stdenv.mkDerivation {
        pname = "libftprintf";
        version = "1.0.0";
        src = ./ft_printf;
        nativeBuildInputs = with pkgs; [
          llvmPackages_12.libcxxClang
        ];
        buildPhase = ''
          export LIBFT_PATH="${libft.packages.${pkgs.system}.default}"
          make
        '';
        installPhase = ''
          mkdir -p $out/lib
          cp libftprintf.a $out/lib
          cp -r include $out/include
        '';
        meta = with pkgs.lib; {
          license = licenses.agpl3Only;
        };
      };
    });
    devShells = forEachSystem ({pkgs}: {
      default = pkgs.mkShell {
        packages = with pkgs; [
          bear
          clang-tools_12
          gnumake
          llvmPackages_12.libcxxClang
          norminette
          valgrind
        ];
      };
    });
  };
}
