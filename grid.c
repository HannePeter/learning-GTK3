#include <stdlib.h>
#include <gtk/gtk.h>
#include "main_window.h"
#include "grid_cb.h"

#define BUTTONS 4


int main(int argc, char **argv)
{
    GtkWidget  *win, *grid, *buttons[BUTTONS];

    gtk_init(&argc, &argv);

    win =           create_window("Eine einfache Tabelle", 300, 200);
    grid =          gtk_grid_new();
    buttons[0] =    gtk_button_new_with_label("Kein schrumpfen\nkein expandieren");
    buttons[1] =    gtk_button_new_with_label("Expandiert und schrumpft\nvertikal");
                    gtk_widget_set_vexpand(buttons[1], TRUE);
    buttons[2] =    gtk_button_new_with_label("Expandiert und schrumpft\nvertikal");
                    gtk_widget_set_vexpand(buttons[2], TRUE);
                    gtk_widget_set_hexpand(buttons[2], TRUE);
    buttons[3] =    gtk_button_new_with_label("[Homogenität ändern]");
                    g_signal_connect(buttons[3], "clicked", G_CALLBACK(change_homogenous), grid);


    gtk_grid_attach(GTK_GRID(grid), buttons[0], 0, 0, 1, 1);            // left  | up
    gtk_grid_attach(GTK_GRID(grid), buttons[1], 0, 1, 1, 1);            // left  | down
    gtk_grid_attach(GTK_GRID(grid), buttons[2], 1, 1, 1, 1);            // right | down
    gtk_grid_attach(GTK_GRID(grid), buttons[3], 1, 0, 1, 1);            // right | up
    gtk_container_add(GTK_CONTAINER(win), grid);

    gtk_widget_show_all(win);
    gtk_main();

    g_print("Die GTK-Hauptschleife wurde beendet!\n");
    return EXIT_SUCCESS;
}

