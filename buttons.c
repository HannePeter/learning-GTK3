#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include "main_window.h"
#include "buttons_cb.h"

#define VBOX    4
#define BUTTONS 4
#define BUF     50

GtkWidget *buttons[BUTTONS], *t_buttons[BUTTONS], *r_buttons[BUTTONS], *c_buttons[BUTTONS];



int main(int argc, char **argv)
{
    GtkWidget *win, *hbox, *vbox[VBOX], *label[VBOX];
    char *button_label[] = {"Toggle-Buttons", "Radio-Buttons", "Check-Buttons", "Programmende"};
    char *vbox_label[] = {"Auswerten der ...", "Toogled Buttons:", "Radio Buttons:", "Check Buttons:"};
    char buf[BUF];


    gtk_init(&argc, &argv);
    
    win = create_window("Verschiedene Buttons", 350, 200);
    hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 10);
    
    for (int i = 0; i < VBOX; i++)
    {
        vbox[i] = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
        label[i] = gtk_label_new(*(vbox_label+i));
    }

    for (int i = 0; i < BUTTONS; i++)                                               
    {
        buttons[i] = gtk_button_new_with_label(*(button_label+i));

        snprintf(buf, BUF, "Toggle %d", i+1);
        t_buttons[i] = gtk_toggle_button_new_with_label(buf);

        snprintf(buf, BUF, "Radio %d", i+1);
        if (i == 0)
            r_buttons[i] = gtk_radio_button_new_with_label(NULL, buf);
        else
            r_buttons[i] = gtk_radio_button_new_with_label_from_widget(GTK_RADIO_BUTTON(r_buttons[0]), buf);

        snprintf(buf, BUF, "Check %d", i+1);
        c_buttons[i] = gtk_check_button_new_with_label(buf);
    }
    
    g_signal_connect(buttons[0], "clicked", G_CALLBACK(toogled_auswerten), NULL);
    g_signal_connect(buttons[1], "clicked", G_CALLBACK(radio_auswerten), NULL);
    g_signal_connect(buttons[2], "clicked", G_CALLBACK(check_auswerten), NULL);
    g_signal_connect(buttons[3], "clicked", G_CALLBACK(end), NULL);

    for (int i = 0; i < VBOX; i++)
    {
        gtk_box_pack_start(GTK_BOX(vbox[i]), label[i], FALSE, FALSE, 0);
        gtk_box_pack_start(GTK_BOX(hbox), vbox[i], FALSE, FALSE, 0);
    }

    for (int i = 0; i < BUTTONS; i++)
    {
        gtk_box_pack_start(GTK_BOX(vbox[0]),   buttons[i], FALSE, FALSE, 0);
        gtk_box_pack_start(GTK_BOX(vbox[1]), t_buttons[i], FALSE, FALSE, 0);
        gtk_box_pack_start(GTK_BOX(vbox[2]), r_buttons[i], FALSE, FALSE, 0);
        gtk_box_pack_start(GTK_BOX(vbox[3]), c_buttons[i], FALSE, FALSE, 0);
    }

    gtk_container_add(GTK_CONTAINER(win), hbox);


    gtk_widget_show_all(win);
    gtk_main();

    puts("Die GTK-Hauptschleife wurde beendet!");
    return EXIT_SUCCESS;
}

