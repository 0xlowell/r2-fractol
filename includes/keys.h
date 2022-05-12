/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzima <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:09:38 by lzima             #+#    #+#             */
/*   Updated: 2022/05/10 14:09:40 by lzima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef KEYCODES_H
# define KEYCODES_H

#  define K_ESC 		53
#  define K_UP 			126
#  define K_DOWN 		125
#  define K_LEFT 		123
#  define K_RIGHT 		124
#  define K_W 			13
#  define K_S 			1
#  define K_A 			0
#  define K_D 			2
#  define K_P 			35
#  define K_MINUS 		27
#  define K_PLUS 		24
#  define K_R 			15
#  define K_U 			32
#  define K_J 			38
#  define K_I 			34
#  define K_K 			40
#  define K_O 			31
#  define K_L 			37

#  define KEYDOWN 		2	/*int (*f)(int keycode, void *param)*/
#  define KEYUP 		3	/*int (*f)(int keycode, void *param)*/
#  define MOUSE_DOWN  	4	/*int (*f)(int button, int x, int y, void *param)*/
#  define MOUSE_UP  	5	/*int (*f)(int button, int x, int y, void *param)*/
#  define ON_MOUSEMOVE  6 	/*int (*f)(int x, int y, void *param)*/
#  define ON_EXPOSE 	12	/*int (*f)(void *param)*/
#  define ON_DESTROY 	17	/*int (*f)(void *param)*/

#endif


