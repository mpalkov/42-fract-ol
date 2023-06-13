

if (pixel_bits != 32)
    color = mlx_get_color_value(mlx, color);

for(int y = 0; y < 360; ++y)
for(int x = 0; x < 640; ++x)
{
    int pixel = (y * line_bytes) + (x * 4);

    if (endian == 1)        // Most significant (Alpha) byte first
    {
        buffer[pixel + 0] = (color >> 24);
        buffer[pixel + 1] = (color >> 16) & 0xFF;
        buffer[pixel + 2] = (color >> 8) & 0xFF;
        buffer[pixel + 3] = (color) & 0xFF;
    }
    else if (endian == 0)   // Least significant (Blue) byte first
    {
        buffer[pixel + 0] = (color) & 0xFF;
        buffer[pixel + 1] = (color >> 8) & 0xFF;
        buffer[pixel + 2] = (color >> 16) & 0xFF;
        buffer[pixel + 3] = (color >> 24);
    }
}