import subprocess

def install_from_readme(file_path="readme.txt"):
    with open(file_path, "r") as f:
        lines = f.readlines()
    for line in lines:
        line = line.strip()
        if line and not line.startswith("#"):
            print(f"Running: {line}")
            subprocess.run(line, shell=True, check=True)

if __name__ == "__main__":
    install_from_readme()
