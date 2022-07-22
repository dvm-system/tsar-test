#!/usr/bin/perl
push @lines, $_;
END {
  while (@lines >= 3) {
    my $s = join '', splice @lines, 0, 3;
    if ($s !~ /^[^:]+:\d+:\d+:.+\^$/s) {
      unshift @lines, $s;
      last
    }
    push @msgs, $s;
  }
  glue_notes(\@msgs);
  print sort @msgs;
  #print_sorted(\@msgs);
  print @lines;
}

sub glue_notes
{
  my $lines = shift;
  my @ret;
  while (defined ($_ = shift @$lines)) {
    if (/^[^:]+:\d+:\d+: (note):.+\^$/s && @ret) {
      $ret[-1] .= $_;
    }
    else {
      push @ret, $_;
    }
  }
  @$lines = @ret
}

sub print_sorted
{
  my @arr = map {
    [($_ =~ /^([^:]+):(\d+):(\d+):/s), $_]
  } @{$_[0]};
  #print join(', ', map "'$_'", @$_), "\n" for @arr;
  my $i = 0;
  for (sort {
      $a->[0] cmp $b->[0] ||
      $a->[1] <=> $b->[1] ||
      $a->[2] <=> $b->[2] ||
      $a cmp $b
    } @arr) {
    print $_->[3];
  }
}

$_ = '' # Make -p command option to behave like -n.
