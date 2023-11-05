# NOTE v1.2

Written by Michael Cromer

## Summary

Take notes from anywhere in the terminal. Filter existing notes based on metadata, and send them to stdout or to your
`$EDITOR`.

## Installation

    git clone

- Make sure the location is in your `$PATH`!

## Usage

    note [OPTIONS] -- [TEXT]

### Inserting new notes

Use
    
    note -- [TEXT]

to create a new note with the provided text.

__NB:__ The double dash is _always_ required to distinguish the note text, even if there are no options used.

### Searching for notes

Notes are stored with the following metadata:
- username
- date (`YYYY-MM-DD`)
- time (`HH:MM:SS`)
- current repo name (`""` if none)
- current repo branch (`""` if none)

Use

    note [OPTIONS]

to filter and then output the mathching notes to `stdout`.

`note` implements many filters. You can filter by any of the above metadata, or by the note text itself. For a full list of options, use `note --help`.

#### Examples

    note -- "my new note"       Add the note "my new note" to the notes file.
    note -m "string"            Display all notes matching "string".
    note -a 2023                Display all notes from the year 2023 onwards.
    note -e -d                  Display today's notes in the editor.
    note -d 2020-01 -- "text"   Display all notes from January 2020,
                                  then add the note "text" to the notes file.
    note -d -X -s               Silently delete all notes from today.
    note -b 2020-03 -xd 2018-01-10 -m "string1|string2" 
                                Display all notes from before March 2020, 
                                  excluding those from 10 January 2018,
                                  and which match "string1" or "string2".
    note -X -l10 -r "my_repo" -xB "hotfix" -m "feature" >> TODO.md
                                Find the last ten notes which are:
                                  from the git repository "my_repo"; 
                                  excluding those from the branch "hotfix";
                                  and which match "feature". 
                                  append them to the TODO.md file,
                                  and delete them from the notes file.

## TODO

- [ ] Move data to initial, make options apply filters directly, so that multiple instances can be applied. E.g. `note
  -m "string1" -m "string2"` will work exactly like `note -m "string1|string2"`
- [ ] Improve/cleanup code base, try to encapsulate behaviour in functions, add comments etc.
- [X] Add option to use current git repo without typing in manually, and another for repo + branch
- [X] Keep -x[char] syntax for negation generally. Find single chars for "repo" and "branch".
- [X] Consider changing the storage values of null git branch and repo. Use case?
- [X] Make note text robust to special characters
- [X] Add flag to remove notes from the database once they've been filtered
- [X] Add flag to dump filtered notes to file (DEPRECATED: user should redirect sdtout to desired file; don't reinvent
  the wheel)
- [X] Consider removing the -x[char] syntax for negation, since this is achievable with regexp anyway...but is it better
  to have the shorthand available? (UPDATED Sun 05 Nov 2023 10:35:04 AEDT)
- [X] Consider improving the flag names (-gr and -gb get annoyingly long with x) (UPDATED Sun 05 Nov 2023 10:35:04
  AEDT)
- [X] ??? Enable editing of notes in place (DEPRECATED: maybe later, but not really useful right now)
