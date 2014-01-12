use 5.010;
use strict;


#mel_pat_1 notes
open(my $pat1, "<mel_pat_1");
open(my $Bb3, ">Bb3");
open(my $Eb4, ">Eb4");
open(my $F4, ">F4");
open(my $D5, ">D5");

#mel_pat_2 notes
open(my $pat2, "<mel_pat_2");
open(my $C5, ">C5");
open(my $A4, ">A4");
my $new;
while(<$pat1>){
	$new = $_;
	$new =~ s/^\d*, //g;
	if(/^58/){
		print $Bb3 $new;
	}elsif(/^63/){
		print $Eb4 $new;
	}elsif(/^65/){
		print $F4 $new;
	}elsif(/^70/){
	print $Bb3 $new;
	}elsif(/^74/){
		print $D5 $new;
	}
}

while(<$pat2>){
	$new = $_;
	$new =~ s/^\d*, //g;
	if(/^72/){
		print $C5 $new;
	}elsif(/^69/){
		print $A4 $new;
	}
}

close($pat1, $Bb3, $Eb4, $F4, $D5);
close($pat2, $C5, $A4);
