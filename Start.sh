make

case "$(uname -s)" in

   Darwin)
     echo 'Mac OS X'
	 osascript -e "tell application \"Terminal\"" -e "tell application \"System Events\"" -e "keystroke \"f\" using {control down, command down}" -e "end tell" -e "end tell"
    ./GOP
     ;;

   Linux)
     echo 'Linux'
     lxterminal --geometry=271x64 -e ./GOP ||konsole --fullscreen -e ./GOP || xfce4-terminal --fullscreen -e ./GOP || mate-terminal --full-screen -e ./GOP || xterm -max -e ./GOP || gnome-terminal --full-screen -e ./GOP 
     ;;


   *)
esac
