```c
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract’ol                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*   PASSED with 125%                                 ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
```

# 42-fract’ol
This project is about creating graphically beautiful fractals.

To see the complete instructions, read the [subject.pdf](https://github.com/mpalkov/42-fract-ol/blob/main/42_files/en.subject.pdf)

<img width="803" alt="image" src="https://github.com/mpalkov/42-fract-ol/assets/102831536/e804ff73-a3d7-44f3-a16f-a4750862a70d">


### The program is split in mandatory and bonus part with the following mandatory features:

    make

the bonus features are not included in the mandatory part. To see the full potential, I recommend to explore only the output of `make bonus`.
### Rendering
• Your program must offer the Julia set and the Mandelbrot set.
• The mouse wheel zooms in and out, almost infinitely (within the limits of the computer). This is the very principle of fractals.
• You must be able to create different Julia sets by passing different parameters to the program.
• A parameter is passed on the command line to define what type of fractal will be displayed in a window. 
	◦ If no parameter is provided, or if the parameter is invalid, the program displays a list of available parameters and exits properly.
• You must use at least a few colors to show the depth of each fractal. It’s even better if you hack away on psychedelic effects. 

### Graphic management
• Your program has to display the image in a window.
• The management of your window must remain smooth (changing to another window, minimizing, and so forth).
• Pressing ESC must close the window and quit the program in a clean way.
• Clicking on the cross on the window’s frame must close the window and quit the program in a clean way.
• The use of the images of the MiniLibX is mandatory.

### Bonus features
    make fclean
    make bonus
• One more different fractal (more than a hundred different types of fractals are referenced online).
• The zoom follows the actual mouse position.
• In addition to the zoom: moving the view by pressing the arrows keys.
• Make the color range shift. - I have used the numeric keys 7 8 and 9 to add color to channels R G and B, and the below line 4 5 and 6 to subtract from the respective channels.


---

# References:

#### What is fractal?
Wikipedia https://en.wikipedia.org/wiki/Fractal

---
#### The most useful article on Mandelbrot with C, I have read:
Mathematical explanation, calculating the Mandelbrot set and further optimize the calculations.
http://warp.povusers.org/Mandelbrot/

---
#### Mandelbrot fractal facts:
A Statistical Investigation of the Area of the Mandelbrot Set PDF: https://www2.pd.infn.it/~lacaprar/Didattica/C++/Complex/Area%20of%20the%20Mandelbrot%20Set.pdf

> The Mandelbrot set (M) has been called the most complex object in
> mathematics, and continues to be the subject of active research. One
> open question is, what is the area of M?
> It is well known that the set is bounded by a circle of radius 2,
> centered at the origin of the complex plane.
> Thus, the area is certainly less than 4π, or approximately 12.6.
> Indeed, the area is much less than that. **The left-most extent of the set
> ends with the spike at x = -2, and the right side extends out
> to approximately x = 0.47. The top and bottom are at approximately
> y = ± 1.12, respectively.** This bounding rectangle has an area of about 5.5,
> and even this is a gross overestimate, as shown.
> Here, M is rendered in a binary fashion: points inside the set
> are colored black and points outside the set are white.
>
>![image](https://github.com/mpalkov/42-fract-ol/assets/102831536/38b0d132-23de-4c61-b5c7-34c67a8921d7)



---
-  https://github.com/lavrenovamaria/42-fract-ol

-   [Veritasium: this equation will change how you see the world](https://www.youtube.com/watch?v=ovJcsL7vyrk)
    
-   [Vsauce: the Mandelbrot Set](https://www.youtube.com/watch?v=MwjsO6aniig)
    
-   [The Mandelbrot Set Explained](https://www.youtube.com/watch?v=7MotVcGvFMg)
    
-   [42Docs. MiniLibX. Getting started](https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html)
    
-   [MiniLibX. Basic introduction, tutorials, tips & tricks.](https://gontjarow.github.io/MiniLibX/mlx-tutorial-create-image.html)
    
-   [Pixel drawing with the minilibx](https://aurelienbrabant.fr/blog/pixel-drawing-with-the-minilibx)
    
-   [Managing events with the minilibx](https://aurelienbrabant.fr/blog/events-with-the-minilibx)
    
-   [RGBA color model](https://en.wikipedia.org/wiki/RGBA_color_model#Representation)
