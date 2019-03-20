baby_tracker_sources = [
  'main.c',
  'baby-tracker-window.c',
]

baby_tracker_deps = [
  dependency('gio-2.0', version: '>= 2.50'),
  dependency('gtk+-3.0', version: '>= 3.22'),
]

gnome = import('gnome')

baby_tracker_sources += gnome.compile_resources('baby-tracker-resources',
  'baby-tracker.gresource.xml',
  c_name: 'baby_tracker_new'
)

executable('baby-tracker', baby_tracker_sources,
  dependencies: baby_tracker_deps,
  install: true,
)