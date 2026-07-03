Import("env")
import os

patch_file = os.path.join(env.get("PROJECT_WORKSPACE_DIR"), ".pio", "libdeps", env.get("PIOENV"), "TFT_eSPI", "Processors", "TFT_eSPI_ESP32_S3.h")
if os.path.exists(patch_file):
    with open(patch_file, "r") as f:
        content = f.read()
    if "#define SPI_PORT FSPI" in content:
        content = content.replace("#define SPI_PORT FSPI", "#define SPI_PORT 2")
        with open(patch_file, "w") as f:
            f.write(content)
