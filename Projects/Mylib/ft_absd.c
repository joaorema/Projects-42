/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_absd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaorema <joaorema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 23:44:50 by joaorema          #+#    #+#             */
/*   Updated: 2025/02/05 23:45:33 by joaorema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double  ft_absd(double nb)
{
    if(nb < 0)
        return (-nb);
    return (nb);
}