# NOTE v1.0

Written by Michael Cromer

## Summary

Take notes from anywhere in the terminal. Filter existing notes based on metadata, and send them to stdout or to your
$EDITOR.

## Installation

    git clone

- Make sure the location is in your $PATH!

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
- date (YYYY-MM-DD)
- time (HH:MM:SS)
- current repo name ($HOME if none)
- current repo branch ("NULL" if none)

Use

    note [OPTIONS]

to filter and then output the mathching notes to stdout.

`note` implements many filters. You can filter by any of the above metadata, or by the note text itself. For a full list of options, use `note --help`.

#### Examples

    note -- "my new note"       Add the note "my new note" to the notes file.
    note -m "string"            Display all notes matching "string".
    note -a 2023                Display all notes from the year 2023 onwards.
    note -e --today             Display today's notes in the editor.
    note -d 2020-01 -- "text"   Display all notes from January 2020,
                                  then add the note "text" to the notes file.
    note -gr "repo" -xgb "hotfix" -m "feature" -l 10
                                Display the last ten notes which are:
                                  from the git repository "repo"; 
                                  excluding those from the branch "hotfix";
                                  and which match "feature".

## TODO

- [ ] Make note text robust to special characters
- [ ] Add flag to dump filtered notes to file
- [ ] Add flag to remove notes from the database once they've been filtered
- [ ] ??? Enable editing of notes in place


