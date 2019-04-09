/* baby-tracker-window.c
 *
 * Copyright 2019 Kurt Meyerhofer
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "baby-tracker-config.h"
#include "baby-tracker-window.h"
#include "baby-tracker-resources.h"
#define HANDY_USE_UNSTABLE_API
#include <handy.h>

struct _BabyTrackerWindow
{
  GtkApplicationWindow  parent_instance;

  /* Template widgets */
  GtkHeaderBar        *header_bar;
  GtkLabel            *label;
};

G_DEFINE_TYPE (BabyTrackerWindow, baby_tracker_window, GTK_TYPE_APPLICATION_WINDOW)

static void
baby_tracker_window_class_init (BabyTrackerWindowClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/io/kcmr/baby-tracker/ui/baby-tracker-window.ui");
  gtk_widget_class_bind_template_child (widget_class, BabyTrackerWindow, header_bar);
  gtk_widget_class_bind_template_child (widget_class, BabyTrackerWindow, label);
}

static void
baby_tracker_window_init (BabyTrackerWindow *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
