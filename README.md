# PipersJewelbots

One of these days, we'll put more information in here. :)

All of this stuff is free.  However, the code in WarEagle, our "music player," may not be used
to play Rammer Jammer, Yea Alabama, or any of that other vile Crimson Tide stuff!

If you do anything cool or you're inspired by anything, please let us know!

Finally, if you have any trouble with any of it, feel free to let us know.

Sincerely,
Piper and Patrick

*Oh, actually finally, none of this is particularly robust.  Don't expect peak performance.  Also,
expect a presence of bugs, defects, and code smells.  :)*

### How to use the music player

##### Write the music
It's just a string of notes with the first character representing the duration:
**w**hole
**h**alf
**q**uarter
**e**ighth
**s**ixteenth

Capitalized letters represent dotted notes.

A **r**est is represented with an `r` followed by the duration like a **q**uarter rest `rq` or an **e**ighth note rest `re`.

Precede notes with a `>` to accent them.  They'll be more intense and the lights will flash.

We didn't add slurs because we aren't playing tones.  We didn't add ties because we were able to get by using existing constructs.  For example, 2 tied (or slurred) quarter notes `qq` is just one half note `h`.  A quarter note tied to an eighth note `qe` is the same as a dotted quarter note `Q`.

Finally, you can specify the number of durations before the note type.  For example, two half notes tied to a quarter note `hhq` can be represented as 5 quarter notes `5q`.

So, you might write Jingle Bells like this:
```
const char* JINGLE_BELLS = "qqqqH eeqqqqw qqqqw qqqqw qqqqw qqqqH qqqqqqqqqqqqqq rq >h qqh qqh qqQew qqqqqqqee qqqqh >h qqh qqh qqQew qqqqqqqee >q >q >q >q w";
```

##### Create a song

A song is music at a tempo.  Create a Jingle Bells song like this:
```
Song jingleBells(200, JINGLE_BELLS);

void button_press(void) {
  jingleBells.play();
}
```

##### Add a light show

A light show is an array if LightScenes.  The patterns will repeat changing with every note.  It can be as long or short as you like.

```
const LightScene CHRISTMAS[] = {
  { RED, GREEN, RED, GREEN },
  { GREEN, RED, GREEN, RED }
};

void setup() {
  jingleBells.addLightShow(ARRAY_SIZE(CHRISTMAS), CHRISTMAS);
}
```



