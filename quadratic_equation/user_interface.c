#include "user_interface.h"
#include "reading_lines.h"
#include "floating_arithmetic.h"
#include "solve_equation.h"
#include <stdio.h>
#include <string.h>

// UI functions | displaying equation

void display_equation_type(equation *data) {
	switch(data->type) {
		case LINEAR_EQUATION:
			printf("This equation is linear!\n");
			break;
		case QUADRATIC_EQUATION:
			printf("This equation is quadratic!\n");
			break;
		case NO_EQUATION_TYPE:
			printf("The equation type is not set\n");
			break;
		default:
		 	printf("Unknown equation type.\n");
			break;
	}
}

void display_D(equation *data, equation_solution *solution) {
	printf("D = %.3f^2 - 4 * (%+.3f) * (%+.3f)\n", data->b, data->a, data->c);
	printf("D = %.3f\n", solution->D);
	
}

void display_roots(equation *data, equation_solution *solution) {
	switch(solution->type) {
		case TWO_ROOTS:
			display_D(data, solution);
			printf("The equation has two roots:\n");
			printf("x1 = %.3f, x2 = %.3f\n", solution->roots[0], solution->roots[1]);
			break;

		case ONE_QUADRATIC_ROOT:
			display_D(data, solution);
			printf("The equation has one root\n");
			printf("x = %.3f\n", solution->roots[0]);
			break;

		case ONE_LINEAR_ROOT:
			printf("The equation has one root:\n");
            printf("x = %.3f\n", solution->roots[0]);
			break;

		case INFINITE_ROOTS:
			printf("That equation has infinite number of roots!\n");
			break;

		case NO_REAL_ROOTS:
			display_D(data, solution);
			printf("Discriminant is negative. The equation has no real roots\n");
			break;

		case NO_ANY_ROOTS:
			printf("That equation has no roots at all.\n");
			break;
		
		default:
		  	printf("Unknown root type.\n"); // TODO: assert?
			break;
	}
}

void store_equation_part(float coef, char* exp, char* equation_buf) { // exp - степень;
	if (!is_equal(coef, 0)) {
        // TODO: sprintf returns how many chars it printed
        //
        // 1. // You can pass shift into buffer that gradually grows
        //    char buffer[256] = {};
        //    size_t shift = 0;
        //
		//    shift += sprintf(buffer + shift, "%d", 5);
		//    shift += sprintf(buffer + shift, "%d", 6);
        //
        // 2. // You can update pointer to point to empty part of the buffer
        //    char buffer[256] = {};
        //    char *place_to_write = buffer;
        //
		//    place_to_write += sprintf(place_to_write, "%d", 5);
		//    place_to_write += sprintf(place_to_write, "%d", 6);

		sprintf(equation_buf, "%s%+f%s", equation_buf, coef, exp); // записывает число в строковый буфер (по пути преобразовывая его)
	}
}

void display_equation(equation *data) {
	float a = data->a, b = data->b, c = data->c;
	char equation_view[100];
	
	equation_view[0] = '\0';

	store_equation_part(a, "x^2", equation_view);
	store_equation_part(b, "x", equation_view);
	store_equation_part(c, "", equation_view);
	

	printf("%s=0\n", equation_view);
	  
}

void print_solution(equation *data, equation_solution *solution) {
	display_equation(data);
	display_equation_type(data);
	display_roots(data, solution);
	printf("Thank you for your attention!\n");
}


void read_coefficients(equation *data) {
	printf("Please, enter coefficients a, b and c. Format: a b c;\n");
	while (true) {
		if (scanf("%f %f %f", &data->a, &data->b, &data->c) != 3) {
			printf("Wrong format. Try again!\n");
			continue;
		}

		if (!are_coefficients_infinity(data->a, data->b, data->c)) {
			break;
		}

		printf("Coefficients can't be infinite. Try again!");
		read_line_end();
	} 
}

