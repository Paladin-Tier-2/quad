# quad-solver

Tiny command-line quadratic equation solver in C (real + complex roots).

## Build

```bash
gcc quad.c -o quad -lm
```

## Usage

```bash
./quad a b c
```

Example:

```bash
./quad 1 -7 10
```

## Install (PATH)

Put the binary in `~/bin` and add it to your PATH.

```bash
mkdir -p ~/bin
cp ./quad ~/bin/
```

Add to `~/.bashrc`:

```bash
export PATH="$HOME/bin:$PATH"
```

Reload:

```bash
source ~/.bashrc
```
