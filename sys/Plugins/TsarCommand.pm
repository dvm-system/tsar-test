package Plugins::TsarCommand;
use strict;
use base qw(Plugins::Base);

sub on_prepare {
  my $class = shift;
  my $task = shift;
  my $pind = \shift;
  my $all_tasks = shift;
  my $task_list = shift;
  my $db = shift;

  my $act = $task->get_var('', 'action');

  for (my $i = $$pind + 1; $i < @$all_tasks; $i++) {
    my $t = $all_tasks->[$i];
    last if $t->plugin eq 'TsarCommand';
    next if $t->plugin ne 'TsarPlugin';
    my $new_id = $t->id.($t->id->args ? ',' : ':')."action=$act";
    $all_tasks->[$i] = $db->new_task($new_id);
  }
}

1;
