#include <gtk/gtk.h>



void change_homogenous(GtkWidget *widget, GtkGrid *grid)
{
    gtk_grid_set_row_homogeneous(grid, !gtk_grid_get_row_homogeneous(grid));
    gtk_grid_set_column_homogeneous(grid, !gtk_grid_get_column_homogeneous(grid));
}

