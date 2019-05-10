#ifndef EVENTS_H
    #define EVENTS_H EVENTS_H

    void show_pos(GtkWidget *widget, GdkEventButton *event, GtkWidget *label);
    void change_label1(GtkWidget *widget, GdkEventButton *event, GtkWidget *label);
    void change_label2(GtkWidget *widget, GdkEventButton *event, GtkWidget *label);
    void key_press(GtkWidget *widget, GdkEventKey *event, GtkWidget *label);

#endif
