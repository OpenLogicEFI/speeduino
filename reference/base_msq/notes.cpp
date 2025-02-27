/*************************************************
    **THIS FILE IS FOR NOTES ONLY!!**
**************************************************
many of the pins defined in the msq don't need to be defined at all thus preventing most errors.
Loading the new msq file puts the first available selection as the default.

example:
 error caused by:  <constant name="Auxin4pina">"A0"</constant>
 no error:         <constant name="Auxin4pina"></constant>

 -Removed irrelevant defined pins in MSQ

**************************************************

Errors that should have "Board Default" (Warning: Parameter in .msq, but not valid for current firmware:) 
 -Added "Board Default" to pins defined in msq. Prevent confusion on boards with defaults anyway.


**************************************************

*/