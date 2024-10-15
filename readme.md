# Vault35 Config
This is just a repository in order to save my own personal config for the [Vault35](https://mechvault.net/products/vault-35-hhkb-pcb)

## Keymaps

### Layers
Layer | Description
------|-------------
BASE  | Layer for regular typing and navigating.
LOWER | Modifier layer and additional action keys.
RAISE | Additional text layer.
ADJUST| Layer for meta actions and mouse keys.

### Custom keys
Symbol | Description
-------|-------------
ZSF    | Single tap or double tap produces `z`, Holding produces `<Shift>`.
SSF    | Single tap or double tap produces `;`, Holding produces `<Shift>`.
TSF    | Single tap or double tap produces `<Tab>` Holding produces `<Shift>`.
HSPC   | Single tap or double tap produces <Space> Holding produces layer shift to Lower.
HBSPC  | Single tap or double tap produces <BackSpace> Holding produces layer shift to Higher.
RGB_T  | Toggle RGB.
RGB_M  | Cycle through RGB modes.
ACC_X  | Set mouse acceleration.
BTNX   | Mouse button x.
MS_X   | Move mouse in direction.
WH_X   | Mouse wheel in direction.
BOOT   | QMK Reboot.
ROT    | Rotary encoder
✖      | Unassigned, will do nothing.
\      | Empty will have the same key as previous layer.

> To get to the ADJUST layer you will have to hold `LOW` and `HIG` together.

### Layout
```
Base
,-----------------------------------------------------------------.
|  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  | ROT |
|   A   |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |   SSF   |
|   ZSF   |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  | ENTER |
|       | CTL | CMD |   HSPC    |   HBSP    | ALT |     |         |
`-----------------------------------------------------------------'

Lower
,-----------------------------------------------------------------.
|  !  |  @  |  #  |  $  |  %  |  ^  |  &  |  *  |  (  |  )  | ROT |
|  ESC  |  F1 |  F2 |  F3 |  ✖  |  -  |  =  |  [  |  ]  |    '    |
|   TSF   |  F4 |  F5 |  F6 |  ✖  | DEL |  ✖  |  ✖  |  /  | ENTER |
|       | CTL | CMD |    SPC    |    BSP    | ALT |     |         |
`-----------------------------------------------------------------'

Raise
,-----------------------------------------------------------------.
|  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  | ROT |
|   `   |  F7 |  F8 |  F9 |  ✖  | LEFT| DOWN|  UP |RIGHT|   SSF   |
|   TSF   | F10 | F11 | F12 |  ✖  |  ✖  |M_PRV|M_PLY|M_NXT| ENTER |
|       | CTL | CMD |    SPC    |    BSP    | ALT |     |         |
`-----------------------------------------------------------------'

Adjust
,-----------------------------------------------------------------.
| BOOT|ACC_0|  ✖  |  ✖  |  ✖  |  ✖  | BTN1| BTN3| BTN2| WH_U| ROT |
| RGB_T |ACC_1|  ✖  |  ✖  |  ✖  | MS_L| MS_D| MS_U| MS_R|  WH_D   |
|  RGB_M  |ACC_2|  ✖  |  ✖  |  ✖  |  ✖  |  ✖  |  ✖  |  ✖  | ENTER |
|       | CTL | CMD |    SPC    |    BSP    | ALT |     |         |
`-----------------------------------------------------------------'


Rotary encoder
,-------.    ,-------.
| ,---. |    | ,---. |
v |   | |    | |   | v
  `---'        `---'
          |
        ,_|_.
       /  v  \
      |\_____/|
      |       |
       \_____/
```
## How to install
Install the QMK Firmware https://github.com/qmk/qmk_firmware

Then clone this repository into the correct place like so
```
# presumed to be in the qmk firmware directory
# first clone the board firmware for the rp version of the vault35
git clone https://github.com/projectcain/Board-Firmware ./keyboards/projectcain

# then clone this config into the rp version
git clone https://github.com/meir/vault35-config ./keyboards/projectcain/vault35rp/keymaps/meir
```

And then compile and flash
```
qmk compile -c -kb projectcain/vault35rp -km meir
qmk flash -kb projectcain/vault35rp -km meir
```
