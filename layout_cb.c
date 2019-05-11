#include <gtk/gtk.h>



void move_button(GtkWidget *button, GtkWidget *layout)
{
    int x;

    gtk_container_child_get(GTK_CONTAINER(layout), button, "x", &x, NULL);
    x = x % 100 + 10;
    gtk_layout_move(GTK_LAYOUT(layout), button, x, 50);
}

