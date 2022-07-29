# cub3d

Cub3D was a project of the 42 coding school in Heilbronn, that we needed to do for the core curriculum.
The task was to recreate a Raycaster which was used for Wolfenstein 3D.
This raycaster was done by [Jonas Hagedorn](https://github.com/Jonabcs) and [Kevin Hirsig](https://github.com/khirsig).

![cub3Dgif](https://user-images.githubusercontent.com/78398628/181726830-bf59cabf-5ffd-4dac-88b7-98b4c1d95f41.gif)

The idea of a raycaster is, that in a 2D Grid Map each Square is either a 0 (no wall) or >= 1 (wall with a certain texture).  
From the view of the player we send out rays, that move forward on the 2D Map until it hits a map-square that is a wall.  
We then calculate the distance from the player to the wall to set the height, that this wall needs to be drawn on the screen with.  
While these are all 2D calculations, we create a 3D look.
Because following the ray with maximum precision would be infinite, we used DDA (Digital Differential Analysis) which finds which squares a line hits.  
With this we can reduce the amount of calculating needed by a lot.
Once the walls are drawn we draw the 2D sprites of the enemies to the player and sort them from furthest away to closest to camera.  
