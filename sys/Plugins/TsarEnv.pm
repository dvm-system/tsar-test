package Plugins::TsarEnv;
use strict;
use Plugins::Base v0.6.1;
use base qw(Plugins::Base);
use Task::ID qw(arg2str);

sub on_prepare {
  my $class = shift;
  my $task = shift;
  my $pind = \shift;
  my $all_tasks = shift;
  my $task_list = shift;
  my $db = shift;

  my $h = $task->id->args_hash;
  my @args = sort map {
    my $g = $_;
    map { (arg2str($g, $_, @{$h->{$g}{$_}})) } keys %{$h->{$g}}
  } keys %$h;
  return if !@args;
  my $args_str = join ',', @args;

  for (my $i = $$pind + 1; $i < @$all_tasks; $i++) {
    my $t = $all_tasks->[$i];
    last if $t->plugin eq 'TsarEnv';
    next if $t->plugin ne 'TsarPlugin';
    my $new_id = $t->id.($t->id->has_args ? ',' : ':').$args_str;
    $all_tasks->[$i] = $db->new_task($new_id);
  }
}

1;
