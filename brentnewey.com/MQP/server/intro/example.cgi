#!/usr/local/bin/perl
use CGI;
use CGI::Carp 'fatalsToBrowser';

print "Content-type:text/html\n\n";

$query = new CGI;

$init = $query -> param('init');
$exp = $query -> param('exp');
$class = $query -> param('class');
$target = $query -> param('radio_button');

print <<EndHTML


<HTML>
<HEAD><TITLE>Example Activity</TITLE>
<script language="javascript">
  <!--
    function checkCorrect(selection) {
	  //check to see if correct button was clicked
	  //how do you get the value for radio_button from previous page
      //alert(selection);
      //alert(radio_button.value);
      
      if (selection == $target){
          document.form1.action="congrats.cgi";
      }
      else {
          document.form1.action="badButton.cgi";
      }
      document.form1.done.value = done;
      document.form1.submit();


   }
  // End -->
</script>

</HEAD>

<BODY>
<blockquote>
<form name="form1" action="" method="POST">
	<h3>Example</h3>

	<p>The most popular music today among young adults
(post-highschool) is alternative rock and techno. Alt. rock has its roots
in the 80s, rejecting the heavy marketing of mainstream rock and
heavy-metal. In general, alternative rock bands recorded for independant
labels and played in small clubs. They refused to conform to the standards
of the rest of the music industry, and often tried to raise awareness of
social issues such as AIDS, environmentalism, depression, suicide, and
abortion rights.<br><a href="badLink.html">Learn
about Gospel music</a>
&nbsp;&nbsp;<input type=submit value="This is My Topic" onClick="checkCorrect('alt')">

	<p>At the beginning of the 20th century, a new breed of music
began gaining popularity. This music sprung from the black community, but
quickly spread to all levels of society. Jazz music was different from the
rest of the music of the day because it was heavily based on
improvisation, with the musicians usually unable to even read music.<br><a
href="badLink.html">Learn about the music of the South</a>
&nbsp;&nbsp;<input type=submit value="This is My Topic" onClick="checkCorrect('jazz')">

	<p>WPI's computer music program is quite excellent. Regular
courses in computerized music are offered two or three times a year, and
many students choose to do independent study projects, or even make
computerized music an integral part of a music sufficiency.<br><a
href="badLink.html">Learn about pop music</a>
&nbsp;&nbsp;<input type=submit value="This is My Topic" onClick="checkCorrect('comp')">

	<p>Beginning in the late 18th century, music of the classical
period generally is very structured, with themes made of short fragments,
often representing several different moods within the same composition.
Chromatics (moving up or down the scale by very small steps) were common.
Composers of this period also incorporated shifts from the major key to
the corresponding minor key. The classical period also made heavy use of
tonic-dominant harmony and the I-IV and I-V cadences that are still used
today. Socially, this is also the time period when comic opera became
popular.<br><a href="badLink.html">Learn about rap music</a>
&nbsp;&nbsp;<input type=submit value="This is My Topic" onClick="checkCorrect('classic')">

<input type="hidden" name="init" value="$init">
<input type="hidden" name="exp" value="$exp">
<input type="hidden" name="class" value="$class">
</form>
</blockquote>
</BODY>
</HTML>

EndHTML
