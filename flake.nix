{
  inputs.nixpkgs.url = "github:nixos/nixpkgs/nixos-unstable";

  outputs = { self, nixpkgs }:
    let pkgs = import nixpkgs { system = "x86_64-linux"; };
    in
    {
      devShell.x86_64-linux = pkgs.mkShell {
        pname = "aoc-c-shell";

        buildInputs = [ pkgs.gnumake pkgs.bear pkgs.doxygen pkgs.graphviz ];
      };
    };
}
