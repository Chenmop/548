/*
* Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
* Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
*
* This program is free software; you can redistribute it and/or modify it
* under the terms of the GNU General Public License as published by the
* Free Software Foundation; either version 2 of the License, or (at your
* option) any later version.
*
* This program is distributed in the hope that it will be useful, but WITHOUT
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
* FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
* more details.
*
* You should have received a copy of the GNU General Public License along
* with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#include "MovementStructures.h"
#include "Player.h"

//5.4.0
MovementStatusElements const PlayerMoveSequence[] =
{
	MSEHasPitch,               // 112
	MSEHasGuidByte2,           // 18
	MSEZeroBit,                // 148
	MSEZeroBit,                // 149
	MSEHasGuidByte0,           // 16
	MSEHasOrientation,         // 48
	MSEHasFallData,            // 140
	MSEHasUnkTime,             // 42
	MSEHasGuidByte3,           // 19
	MSEHasFallDirection,       // 136
	MSEHasTransportData,       // 104
	MSEHasGuidByte4,           // 20
	MSEHasTransportGuidByte5,  // 61
	MSEHasTransportGuidByte4,  // 60
	MSEHasTransportGuidByte7,  // 63
	MSEHasTransportGuidByte2,  // 58
	MSEHasTransportGuidByte6,  // 62
	MSEHasTransportTime2,      // 92
	MSEHasTransportGuidByte3,  // 59
	MSEHasTransportGuidByte1,  // 57
	MSEHasTransportTime3,      // 100
	MSEHasTransportGuidByte0,  // 56
	MSEHasSplineElevation,     // 144
	MSEHasMovementFlags,       // 6
	MSEZeroBit,                // 172
	MSEMovementFlags,          // 6
	MSEHasMovementFlags2,      // 7
	MSEHasGuidByte7,           // 23
	MSEHasGuidByte1,           // 17
	MSEHasTimestamp,           // 8
	MSEMovementFlags2,         // 7
	MSEHasGuidByte5,           // 21
	MSECounterCount,            // 38
	MSEHasGuidByte6,           // 22
	MSEPositionY,              // 40
	MSETransportGuidByte7,     // 63
	MSETransportTime2,         // 88 (22)
	MSETransportPositionX,     // 64
	MSETransportGuidByte5,     // 61
	MSETransportSeat,          // 80
	MSETransportGuidByte2,     // 58
	MSETransportGuidByte0,     // 56
	MSETransportGuidByte3,     // 59
	MSETransportTime,          // 84 (21)
	MSETransportGuidByte4,     // 60
	MSETransportPositionZ,     // 72
	MSETransportGuidByte1,     // 57
	MSETransportPositionY,     // 68
	MSETransportOrientation,   // 76
	MSETransportGuidByte6,     // 62
	MSETransportTime3,         // 24
	MSEGuidByte5,              // 21
	MSEGuidByte1,              // 17
	MSEPositionZ,              // 44
	MSETimestamp,              // 8
	MSEOrientation,            // 48
	MSEGuidByte3,              // 19
	MSEFallSinAngle,           // 128
	MSEFallHorizontalSpeed,    // 132
	MSEFallCosAngle,           // 124
	MSEFallVerticalSpeed,      // 120
	MSEFallTime,               // 29
	MSEGuidByte0,              // 16
	MSEPitch,                  // 112
	MSEGuidByte2,              // 18
	MSEGuidByte6,              // 22
	MSESplineElevation,        // 144
	MSECounter,                // 42
	MSEPositionX,              // 36
	MSEGuidByte4,              // 20
	MSEGuidByte7,              // 23
	MSEEnd
};

//5.4.0
MovementStatusElements const MovementFallLandSequence[] =
{
	MSEPositionY,              // 40
	MSEPositionZ,              // 44
	MSEPositionX,              // 36
	MSEHasFallData,            // 140
	MSEZeroBit,                // 172
	MSEZeroBit,                // 148
	MSEHasTimestamp,           // 32
	MSEHasGuidByte7,           // 23
	MSEZeroBit,                // 149
	MSEHasSplineElevation,     // 144
	MSEHasGuidByte5,           // 21
	MSEHasPitch,               // 112
	MSEHasMovementFlags2,      // 28
	MSEHasGuidByte2,           // 18
	MSEHasGuidByte3,           // 19
	MSEHasGuidByte0,           // 16
	MSEHasOrientation,         // 48
	MSECounterCount,            // 152
	MSEHasMovementFlags,       // 24
	MSEHasUnkTime,             // 168
	MSEHasGuidByte1,           // 17
	MSEHasTransportData,       // 104
	MSEHasGuidByte6,           // 22
	MSEHasGuidByte4,           // 20
	MSEHasTransportGuidByte0,  // 56
	MSEHasTransportTime2,      // 92
	MSEHasTransportGuidByte3,  // 59
	MSEHasTransportGuidByte5,  // 61
	MSEHasTransportGuidByte1,  // 57
	MSEHasTransportGuidByte7,  // 63
	MSEHasTransportGuidByte4,  // 60
	MSEHasTransportGuidByte2,  // 58
	MSEHasTransportGuidByte6,  // 62
	MSEHasTransportTime3,      // 100
	MSEMovementFlags2,         // 28
	MSEHasFallDirection,       // 136
	MSEMovementFlags,          // 24
	MSEGuidByte4,              // 20
	MSEGuidByte3,              // 19
	MSEGuidByte7,              // 23
	MSEGuidByte0,              // 16
	MSEGuidByte2,              // 18
	MSEGuidByte5,              // 21
	MSEGuidByte1,              // 17
	MSEGuidByte6,              // 22
	MSECounter,                 // 156
	MSEFallSinAngle,           // 128
	MSEFallHorizontalSpeed,    // 132
	MSEFallCosAngle,           // 124
	MSEFallTime,               // 116
	MSEFallVerticalSpeed,      // 120
	MSETransportGuidByte4,     // 60
	MSETransportPositionY,     // 68
	MSETransportOrientation,   // 76
	MSETransportPositionZ,     // 72
	MSETransportSeat,          // 80
	MSETransportGuidByte3,     // 59
	MSETransportGuidByte6,     // 62
	MSETransportTime2,         // 88
	MSETransportGuidByte2,     // 58
	MSETransportGuidByte1,     // 57
	MSETransportGuidByte5,     // 61
	MSETransportTime3,         // 96
	MSETransportTime,          // 84
	MSETransportPositionX,     // 64
	MSETransportGuidByte7,     // 63
	MSETransportGuidByte0,     // 56
	MSECounter,                // 168
	MSETimestamp,              // 32
	MSESplineElevation,        // 144
	MSEPitch,                  // 112
	MSEOrientation,            // 48
	MSEEnd
};

//5.1.0 16357 OK
MovementStatusElements const MovementFallResetSequence[] =
{
    MSEPositionY,
    MSEPositionX,
    MSEPositionZ,
    MSEHasGuidByte2,
    MSEHasPitch,
    MSEHasGuidByte0,
    MSEZeroBit,
    MSEHasOrientation,
    //MSEIsAlive,
    MSEZeroBit,
    MSEHasFallData,
    //MSEHasCounter,
    MSEHasMovementFlags2,
    MSEHasSpline,
    MSEHasGuidByte7,
    MSEHasTransportData,
    MSEHasTimestamp,
    MSEHasGuidByte5,
    MSEHasSplineElevation,
    MSEHasGuidByte3,
    MSEHasMovementFlags,
    MSEHasGuidByte1,
    MSEHasGuidByte4,
    MSEHasGuidByte6,
    MSEHasTransportGuidByte4,
    MSEHasTransportGuidByte1,
    MSEHasTransportTime3,
    MSEHasTransportGuidByte2,
    MSEHasTransportGuidByte3,
    MSEHasTransportGuidByte7,
    MSEHasTransportGuidByte0,
    MSEHasTransportTime2,
    MSEHasTransportGuidByte5,
    MSEHasTransportGuidByte6,
    MSEHasFallDirection,
    MSEMovementFlags2,
    MSEMovementFlags,
    MSEGuidByte1,
    MSEGuidByte0,
    MSEGuidByte7,
    MSECounter,
    MSEGuidByte5,
    MSEGuidByte6,
    MSEGuidByte2,
    MSEGuidByte3,
    MSEGuidByte4,
    MSETransportPositionX,
    MSETransportGuidByte0,
    MSETransportTime2,
    MSETransportGuidByte4,
    MSETransportGuidByte5,
    MSETransportGuidByte3,
    MSETransportSeat,
    MSETransportGuidByte7,
    MSETransportOrientation,
    MSETransportPositionZ,
    MSETransportPositionY,
    MSETransportGuidByte6,
    MSETransportTime,
    MSETransportGuidByte2,
    MSETransportTime3,
    MSETransportGuidByte1,
    MSEPitch,
    MSEFallCosAngle,
    MSEFallSinAngle,
    MSEFallHorizontalSpeed,
    MSEFallVerticalSpeed,
    MSEFallTime,
    MSEOrientation,
    MSETimestamp,
    MSESplineElevation,
    //MSEAlive,
    MSEEnd,
};

//5.4.0
MovementStatusElements const MovementHeartBeatSequence[] =
{
	MSEPositionZ,              // 44
	MSEPositionX,              // 36
	MSEPositionY,              // 40
	MSECounterCount,            // 152
	MSEHasMovementFlags,       // 24
	MSEZeroBit,                // 148
	MSEHasUnkTime,             // 168
	MSEHasGuidByte3,           // 19
	MSEHasGuidByte6,           // 22
	MSEHasPitch,               // 112
	MSEZeroBit,                // 149
	MSEZeroBit,                // 172
	MSEHasGuidByte7,           // 23
	MSEHasGuidByte2,           // 18
	MSEHasGuidByte4,           // 20
	MSEHasMovementFlags2,      // 28
	MSEHasOrientation,         // 48
	MSEHasTimestamp,           // 32
	MSEHasTransportData,       // 104
	MSEHasFallData,            // 140
	MSEHasGuidByte5,           // 21
	MSEHasSplineElevation,     // 144
	MSEHasGuidByte1,           // 17
	MSEHasGuidByte0,           // 16
	MSEHasTransportGuidByte5,  // 61
	MSEHasTransportGuidByte3,  // 59
	MSEHasTransportGuidByte6,  // 62
	MSEHasTransportGuidByte0,  // 56
	MSEHasTransportGuidByte7,  // 63
	MSEHasTransportTime3,      // 100
	MSEHasTransportGuidByte1,  // 57
	MSEHasTransportGuidByte2,  // 58
	MSEHasTransportGuidByte4,  // 60
	MSEHasTransportTime2,      // 92
	MSEMovementFlags,          // 24
	MSEHasFallDirection,       // 136
	MSEMovementFlags2,         // 28
	MSEGuidByte2,              // 18
	MSEGuidByte3,              // 19
	MSEGuidByte6,              // 22
	MSEGuidByte1,              // 17
	MSEGuidByte4,              // 20
	MSEGuidByte7,              // 23
	MSECounter,                 // 156
	MSEGuidByte5,              // 21
	MSEGuidByte0,              // 16
	MSEFallSinAngle,           // 128
	MSEFallCosAngle,           // 124
	MSEFallHorizontalSpeed,    // 132
	MSEFallVerticalSpeed,      // 120
	MSEFallTime,               // 116
	MSETransportGuidByte1,     // 57
	MSETransportGuidByte3,     // 59
	MSETransportGuidByte2,     // 58
	MSETransportGuidByte0,     // 56
	MSETransportTime3,         // 96
	MSETransportSeat,          // 80
	MSETransportGuidByte7,     // 63
	MSETransportPositionX,     // 64
	MSETransportGuidByte4,     // 60
	MSETransportTime2,         // 88
	MSETransportPositionY,     // 68
	MSETransportGuidByte6,     // 62
	MSETransportGuidByte5,     // 61
	MSETransportPositionZ,     // 72
	MSETransportTime,          // 84
	MSETransportOrientation,   // 76
	MSECounter,                // 168
	MSEOrientation,            // 48
	MSEPitch,                  // 112
	MSETimestamp,              // 32
	MSESplineElevation,        // 144
	MSEEnd
};

//5.4.0
MovementStatusElements const MovementJumpSequence[] =
{
	MSEPositionY,              // 40
	MSEPositionX,              // 36
	MSEPositionZ,              // 44
	MSEHasGuidByte1,           // 17
	MSEHasGuidByte7,           // 23
	MSEHasMovementFlags2,      // 28
	MSEHasGuidByte5,           // 21
	MSEHasSplineElevation,     // 144
	MSEHasOrientation,         // 48
	MSEHasGuidByte6,           // 22
	MSEHasGuidByte4,           // 20
	MSEZeroBit,                // 149
	MSEHasTransportData,       // 104
	MSEZeroBit,                // 148
	MSECounterCount,            // 152
	MSEHasPitch,               // 112
	MSEHasMovementFlags,       // 24
	MSEHasTimestamp,           // 32
	MSEHasUnkTime,             // 168
	MSEHasGuidByte3,           // 19
	MSEZeroBit,                // 172
	MSEHasFallData,            // 140
	MSEHasGuidByte2,           // 18
	MSEHasGuidByte0,           // 16
	MSEHasTransportGuidByte2,  // 58
	MSEHasTransportGuidByte3,  // 59
	MSEHasTransportGuidByte1,  // 57
	MSEHasTransportGuidByte4,  // 60
	MSEHasTransportTime2,      // 92
	MSEHasTransportGuidByte5,  // 61
	MSEHasTransportGuidByte6,  // 62
	MSEHasTransportGuidByte0,  // 56
	MSEHasTransportGuidByte7,  // 63
	MSEHasTransportTime3,      // 100
	MSEMovementFlags,          // 24
	MSEMovementFlags2,         // 28
	MSEHasFallDirection,       // 136
	MSEGuidByte7,              // 23
	MSEGuidByte1,              // 17
	MSEGuidByte0,              // 16
	MSECounter,                 // 156
	MSEGuidByte2,              // 18
	MSEGuidByte6,              // 22
	MSEGuidByte3,              // 19
	MSEGuidByte4,              // 20
	MSEGuidByte5,              // 21
	MSEFallVerticalSpeed,      // 120
	MSEFallSinAngle,           // 128
	MSEFallCosAngle,           // 124
	MSEFallHorizontalSpeed,    // 132
	MSEFallTime,               // 116
	MSETransportGuidByte5,     // 61
	MSETransportGuidByte7,     // 63
	MSETransportSeat,          // 80
	MSETransportGuidByte4,     // 60
	MSETransportGuidByte0,     // 56
	MSETransportPositionZ,     // 72
	MSETransportGuidByte6,     // 62
	MSETransportGuidByte2,     // 58
	MSETransportPositionY,     // 68
	MSETransportTime,          // 84
	MSETransportPositionX,     // 64
	MSETransportTime2,         // 88
	MSETransportGuidByte1,     // 57
	MSETransportGuidByte3,     // 59
	MSETransportTime3,         // 96
	MSETransportOrientation,   // 76
	MSESplineElevation,        // 144
	MSEOrientation,            // 48
	MSEPitch,                  // 112
	MSECounter,                // 168
	MSETimestamp,              // 32
	MSEEnd
};

//5.4.0
MovementStatusElements const MovementSetFacingSequence[] =
{
	MSEPositionY,              // 40
	MSEPositionX,              // 36
	MSEPositionZ,              // 44
	MSEHasGuidByte5,           // 21
	MSEHasMovementFlags2,      // 28
	MSEHasGuidByte3,           // 19
	MSEHasGuidByte2,           // 18
	MSECounterCount,            // 152
	MSEZeroBit,                // 172
	MSEHasPitch,               // 112
	MSEHasGuidByte0,           // 16
	MSEHasOrientation,         // 48
	MSEHasTimestamp,           // 32
	MSEZeroBit,                // 148
	MSEHasUnkTime,             // 168
	MSEHasGuidByte4,           // 20
	MSEZeroBit,                // 149
	MSEHasGuidByte1,           // 17
	MSEHasGuidByte6,           // 22
	MSEHasFallData,            // 140
	MSEHasMovementFlags,       // 24
	MSEHasSplineElevation,     // 144
	MSEHasTransportData,       // 104
	MSEHasGuidByte7,           // 23
	MSEHasTransportGuidByte7,  // 63
	MSEHasTransportGuidByte0,  // 56
	MSEHasTransportTime2,      // 92
	MSEHasTransportGuidByte3,  // 59
	MSEHasTransportGuidByte6,  // 62
	MSEHasTransportTime3,      // 100
	MSEHasTransportGuidByte2,  // 58
	MSEHasTransportGuidByte5,  // 61
	MSEHasTransportGuidByte1,  // 57
	MSEHasTransportGuidByte4,  // 60
	MSEHasFallDirection,       // 136
	MSEMovementFlags2,         // 28
	MSEMovementFlags,          // 24
	MSECounter,                 // 156
	MSEGuidByte0,              // 16
	MSEGuidByte6,              // 22
	MSEGuidByte3,              // 19
	MSEGuidByte1,              // 17
	MSEGuidByte2,              // 18
	MSEGuidByte7,              // 23
	MSEGuidByte4,              // 20
	MSEGuidByte5,              // 21
	MSETransportGuidByte0,     // 56
	MSETransportGuidByte2,     // 58
	MSETransportOrientation,   // 76
	MSETransportGuidByte7,     // 63
	MSETransportTime3,         // 96
	MSETransportGuidByte5,     // 61
	MSETransportTime,          // 84
	MSETransportPositionX,     // 64
	MSETransportTime2,         // 88
	MSETransportPositionZ,     // 72
	MSETransportSeat,          // 80
	MSETransportPositionY,     // 68
	MSETransportGuidByte4,     // 60
	MSETransportGuidByte3,     // 59
	MSETransportGuidByte6,     // 62
	MSETransportGuidByte1,     // 57
	MSEFallTime,               // 116
	MSEFallVerticalSpeed,      // 120
	MSEFallHorizontalSpeed,    // 132
	MSEFallSinAngle,           // 128
	MSEFallCosAngle,           // 124
	MSECounter,                // 168
	MSETimestamp,              // 32
	MSESplineElevation,        // 144
	MSEOrientation,            // 48
	MSEPitch,                  // 112
	MSEEnd
};

//5.4.0
MovementStatusElements const MovementSetPitchSequence[] =
{
	MSEPositionZ,              // 44
	MSEPositionX,              // 36
	MSEPositionY,              // 40
	MSEHasMovementFlags,       // 24
	MSEZeroBit,                // 149
	MSEHasGuidByte4,           // 20
	MSEHasTransportData,       // 104
	MSEHasGuidByte7,           // 23
	MSEHasTimestamp,           // 32
	MSEHasGuidByte0,           // 16
	MSEHasMovementFlags2,      // 28
	MSEHasGuidByte5,           // 21
	MSEHasUnkTime,             // 168
	MSEZeroBit,                // 172
	MSEHasGuidByte2,           // 18
	MSECounterCount,            // 152
	MSEHasOrientation,         // 48
	MSEHasPitch,               // 112
	MSEHasSplineElevation,     // 144
	MSEHasGuidByte6,           // 22
	MSEHasGuidByte1,           // 17
	MSEZeroBit,                // 148
	MSEHasFallData,            // 140
	MSEHasGuidByte3,           // 19
	MSEHasTransportGuidByte1,  // 57
	MSEHasTransportGuidByte3,  // 59
	MSEHasTransportGuidByte5,  // 61
	MSEHasTransportGuidByte7,  // 63
	MSEHasTransportGuidByte6,  // 62
	MSEHasTransportTime2,      // 92
	MSEHasTransportGuidByte2,  // 58
	MSEHasTransportTime3,      // 100
	MSEHasTransportGuidByte4,  // 60
	MSEHasTransportGuidByte0,  // 56
	MSEHasFallDirection,       // 136
	MSEMovementFlags,          // 24
	MSEMovementFlags2,         // 28
	MSEGuidByte2,              // 18
	MSEGuidByte4,              // 20
	MSEGuidByte5,              // 21
	MSEGuidByte6,              // 22
	MSEGuidByte0,              // 16
	MSECounter,                 // 156
	MSEGuidByte3,              // 19
	MSEGuidByte7,              // 23
	MSEGuidByte1,              // 17
	MSESplineElevation,        // 144
	MSETransportPositionZ,     // 72
	MSETransportGuidByte3,     // 59
	MSETransportGuidByte2,     // 58
	MSETransportTime3,         // 96
	MSETransportGuidByte5,     // 61
	MSETransportTime2,         // 88
	MSETransportGuidByte6,     // 62
	MSETransportTime,          // 84
	MSETransportGuidByte4,     // 60
	MSETransportSeat,          // 80
	MSETransportOrientation,   // 76
	MSETransportPositionY,     // 68
	MSETransportGuidByte1,     // 57
	MSETransportGuidByte7,     // 63
	MSETransportPositionX,     // 64
	MSETransportGuidByte0,     // 56
	MSEFallHorizontalSpeed,    // 132
	MSEFallSinAngle,           // 128
	MSEFallCosAngle,           // 124
	MSEFallTime,               // 116
	MSEFallVerticalSpeed,      // 120
	MSECounter,                // 168
	MSETimestamp,              // 32
	MSEOrientation,            // 48
	MSEPitch,                  // 112
	MSEEnd
};

//5.4.0
MovementStatusElements MovementStartBackwardSequence[] =
{
	MSEPositionY,              // 40
	MSEPositionZ,              // 44
	MSEPositionX,              // 36
	MSEHasTimestamp,           // 32
	MSEHasOrientation,         // 48
	MSEHasGuidByte7,           // 23
	MSEHasGuidByte2,           // 18
	MSECounterCount,            // 152
	MSEHasFallData,            // 140
	MSEZeroBit,                // 172
	MSEHasGuidByte5,           // 21
	MSEHasGuidByte3,           // 19
	MSEHasGuidByte6,           // 22
	MSEHasSplineElevation,     // 144
	MSEHasGuidByte4,           // 20
	MSEHasTransportData,       // 104
	MSEHasGuidByte0,           // 16
	MSEHasMovementFlags,       // 24
	MSEHasPitch,               // 112
	MSEHasUnkTime,             // 168
	MSEHasMovementFlags2,      // 28
	MSEZeroBit,                // 148
	MSEHasGuidByte1,           // 17
	MSEZeroBit,                // 149
	MSEHasTransportGuidByte1,  // 57
	MSEHasTransportTime2,      // 92
	MSEHasTransportGuidByte0,  // 56
	MSEHasTransportGuidByte7,  // 63
	MSEHasTransportTime3,      // 100
	MSEHasTransportGuidByte3,  // 59
	MSEHasTransportGuidByte5,  // 61
	MSEHasTransportGuidByte6,  // 62
	MSEHasTransportGuidByte2,  // 58
	MSEHasTransportGuidByte4,  // 60
	MSEMovementFlags2,         // 28
	MSEMovementFlags,          // 24
	MSEHasFallDirection,       // 136
	MSECounter,                 // 156
	MSEGuidByte1,              // 17
	MSEGuidByte3,              // 19
	MSEGuidByte5,              // 21
	MSEGuidByte2,              // 18
	MSEGuidByte0,              // 16
	MSEGuidByte4,              // 20
	MSEGuidByte7,              // 23
	MSEGuidByte6,              // 22
	MSECounter,                // 168
	MSETransportTime,          // 84
	MSETransportGuidByte4,     // 60
	MSETransportGuidByte1,     // 57
	MSETransportGuidByte5,     // 61
	MSETransportGuidByte3,     // 59
	MSETransportGuidByte6,     // 62
	MSETransportSeat,          // 80
	MSETransportOrientation,   // 76
	MSETransportPositionX,     // 64
	MSETransportGuidByte0,     // 56
	MSETransportPositionY,     // 68
	MSETransportTime3,         // 96
	MSETransportGuidByte7,     // 63
	MSETransportTime2,         // 88
	MSETransportPositionZ,     // 72
	MSETransportGuidByte2,     // 58
	MSEOrientation,            // 48
	MSEFallTime,               // 116
	MSEFallSinAngle,           // 128
	MSEFallCosAngle,           // 124
	MSEFallHorizontalSpeed,    // 132
	MSEFallVerticalSpeed,      // 120
	MSEPitch,                  // 112
	MSETimestamp,              // 32
	MSESplineElevation,        // 144
	MSEEnd
};

//5.4.0
MovementStatusElements const MovementStartForwardSequence[] =
{
	MSEPositionZ,              // 44
	MSEPositionX,              // 36
	MSEPositionY,              // 40
	MSEHasMovementFlags2,      // 28
	MSEZeroBit,                // 149
	MSEHasUnkTime,             // 168
	MSEZeroBit,                // 148
	MSEHasGuidByte0,           // 16
	MSEHasOrientation,         // 48
	MSEHasFallData,            // 140
	MSECounterCount,            // 152
	MSEHasGuidByte4,           // 20
	MSEHasGuidByte1,           // 17
	MSEHasTimestamp,           // 32
	MSEHasGuidByte7,           // 23
	MSEHasPitch,               // 112
	MSEHasTransportData,       // 104
	MSEHasGuidByte5,           // 21
	MSEHasMovementFlags,       // 24
	MSEHasGuidByte3,           // 19
	MSEHasSplineElevation,     // 144
	MSEHasGuidByte2,           // 18
	MSEHasGuidByte6,           // 22
	MSEZeroBit,                // 172
	MSEHasTransportGuidByte1,  // 57
	MSEHasTransportTime3,      // 100
	MSEHasTransportGuidByte3,  // 59
	MSEHasTransportGuidByte4,  // 60
	MSEHasTransportGuidByte2,  // 58
	MSEHasTransportGuidByte5,  // 61
	MSEHasTransportGuidByte0,  // 56
	MSEHasTransportGuidByte7,  // 63
	MSEHasTransportGuidByte6,  // 62
	MSEHasTransportTime2,      // 92
	MSEHasFallDirection,       // 136
	MSEMovementFlags2,         // 28
	MSEMovementFlags,          // 24
	MSEGuidByte1,              // 17
	MSEGuidByte6,              // 22
	MSEGuidByte7,              // 23
	MSECounter,                 // 156
	MSEGuidByte5,              // 21
	MSEGuidByte0,              // 16
	MSEGuidByte3,              // 19
	MSEGuidByte2,              // 18
	MSEGuidByte4,              // 20
	MSETransportGuidByte3,     // 59
	MSETransportGuidByte1,     // 57
	MSETransportGuidByte6,     // 62
	MSETransportPositionZ,     // 72
	MSETransportGuidByte4,     // 60
	MSETransportTime3,         // 96
	MSETransportSeat,          // 80
	MSETransportGuidByte7,     // 63
	MSETransportOrientation,   // 76
	MSETransportTime2,         // 88
	MSETransportGuidByte5,     // 61
	MSETransportGuidByte2,     // 58
	MSETransportPositionX,     // 64
	MSETransportGuidByte0,     // 56
	MSETransportPositionY,     // 68
	MSETransportTime,          // 84
	MSEFallCosAngle,           // 124
	MSEFallSinAngle,           // 128
	MSEFallHorizontalSpeed,    // 132
	MSEFallTime,               // 116
	MSEFallVerticalSpeed,      // 120
	MSETimestamp,              // 32
	MSEPitch,                  // 112
	MSESplineElevation,        // 144
	MSEOrientation,            // 48
	MSECounter,                // 168
	MSEEnd
};

//5.4.0
MovementStatusElements const MovementStartStrafeLeftSequence[] =
{
	MSEPositionY,              // 40
	MSEPositionZ,              // 44
	MSEPositionX,              // 36
	MSEHasGuidByte0,           // 16
	MSEHasTimestamp,           // 32
	MSEHasGuidByte3,           // 19
	MSEHasMovementFlags2,      // 28
	MSEHasPitch,               // 112
	MSEZeroBit,                // 148
	MSEHasGuidByte2,           // 18
	MSEZeroBit,                // 149
	MSEHasTransportData,       // 104
	MSEHasFallData,            // 140
	MSEHasGuidByte5,           // 21
	MSECounterCount,            // 152
	MSEZeroBit,                // 172
	MSEHasGuidByte4,           // 20
	MSEHasOrientation,         // 48
	MSEHasSplineElevation,     // 144
	MSEHasGuidByte7,           // 23
	MSEHasUnkTime,             // 168
	MSEHasGuidByte1,           // 17
	MSEHasGuidByte6,           // 22
	MSEHasMovementFlags,       // 24
	MSEHasTransportGuidByte0,  // 56
	MSEHasTransportGuidByte2,  // 58
	MSEHasTransportGuidByte1,  // 57
	MSEHasTransportGuidByte6,  // 62
	MSEHasTransportGuidByte7,  // 63
	MSEHasTransportGuidByte3,  // 59
	MSEHasTransportGuidByte5,  // 61
	MSEHasTransportTime3,      // 100
	MSEHasTransportTime2,      // 92
	MSEHasTransportGuidByte4,  // 60
	MSEMovementFlags,          // 24
	MSEHasFallDirection,       // 136
	MSEMovementFlags2,         // 28
	MSEGuidByte0,              // 16
	MSEGuidByte2,              // 18
	MSECounter,                 // 156
	MSEGuidByte3,              // 19
	MSEGuidByte5,              // 21
	MSEGuidByte1,              // 17
	MSEGuidByte7,              // 23
	MSEGuidByte4,              // 20
	MSEGuidByte6,              // 22
	MSETransportGuidByte2,     // 58
	MSETransportPositionZ,     // 72
	MSETransportTime3,         // 96
	MSETransportGuidByte6,     // 62
	MSETransportGuidByte3,     // 59
	MSETransportOrientation,   // 76
	MSETransportGuidByte5,     // 61
	MSETransportTime2,         // 88
	MSETransportGuidByte1,     // 57
	MSETransportPositionY,     // 68
	MSETransportGuidByte4,     // 60
	MSETransportTime,          // 84
	MSETransportSeat,          // 80
	MSETransportPositionX,     // 64
	MSETransportGuidByte0,     // 56
	MSETransportGuidByte7,     // 63
	MSEPitch,                  // 112
	MSETimestamp,              // 32
	MSEFallTime,               // 116
	MSEFallCosAngle,           // 124
	MSEFallHorizontalSpeed,    // 132
	MSEFallSinAngle,           // 128
	MSEFallVerticalSpeed,      // 120
	MSECounter,                // 168
	MSESplineElevation,        // 144
	MSEOrientation,            // 48
	MSEEnd
};

//5.4.0
MovementStatusElements const MovementStartStrafeRightSequence[] =
{
	MSEPositionY,              // 40
	MSEPositionX,              // 36
	MSEPositionZ,              // 44
	MSEHasGuidByte0,           // 16
	MSEHasFallData,            // 140
	MSECounterCount,            // 152
	MSEHasGuidByte7,           // 23
	MSEHasGuidByte6,           // 22
	MSEHasGuidByte4,           // 20
	MSEHasMovementFlags,       // 24
	MSEHasGuidByte5,           // 21
	MSEHasSplineElevation,     // 144
	MSEHasGuidByte3,           // 19
	MSEZeroBit,                // 149
	MSEHasTransportData,       // 104
	MSEHasUnkTime,             // 168
	MSEHasGuidByte1,           // 17
	MSEZeroBit,                // 172
	MSEHasGuidByte2,           // 18
	MSEHasPitch,               // 112
	MSEHasMovementFlags2,      // 28
	MSEHasOrientation,         // 48
	MSEZeroBit,                // 148
	MSEHasTimestamp,           // 32
	MSEHasFallDirection,       // 136
	MSEHasTransportGuidByte1,  // 57
	MSEHasTransportGuidByte6,  // 62
	MSEHasTransportGuidByte3,  // 59
	MSEHasTransportGuidByte5,  // 61
	MSEHasTransportGuidByte2,  // 58
	MSEHasTransportGuidByte0,  // 56
	MSEHasTransportGuidByte4,  // 60
	MSEHasTransportTime3,      // 100
	MSEHasTransportGuidByte7,  // 63
	MSEHasTransportTime2,      // 92
	MSEMovementFlags,          // 24
	MSEMovementFlags2,         // 28
	MSEGuidByte6,              // 22
	MSEGuidByte7,              // 23
	MSEGuidByte0,              // 16
	MSEGuidByte4,              // 20
	MSEGuidByte1,              // 17
	MSECounter,                 // 156
	MSEGuidByte2,              // 18
	MSEGuidByte3,              // 19
	MSEGuidByte5,              // 21
	MSEPitch,                  // 112
	MSETransportGuidByte1,     // 57
	MSETransportSeat,          // 80
	MSETransportGuidByte3,     // 59
	MSETransportTime2,         // 88
	MSETransportGuidByte7,     // 63
	MSETransportTime3,         // 96
	MSETransportGuidByte5,     // 61
	MSETransportGuidByte6,     // 62
	MSETransportGuidByte2,     // 58
	MSETransportGuidByte0,     // 56
	MSETransportTime,          // 84
	MSETransportOrientation,   // 76
	MSETransportPositionY,     // 68
	MSETransportPositionZ,     // 72
	MSETransportGuidByte4,     // 60
	MSETransportPositionX,     // 64
	MSETimestamp,              // 32
	MSEFallVerticalSpeed,      // 120
	MSEFallCosAngle,           // 124
	MSEFallHorizontalSpeed,    // 132
	MSEFallSinAngle,           // 128
	MSEFallTime,               // 116
	MSEOrientation,            // 48
	MSECounter,                // 168
	MSESplineElevation,        // 144
	MSEEnd
};

//5.4.0
MovementStatusElements const MovementStartTurnLeftSequence[] =
{
	MSEPositionZ,              // 44
	MSEPositionX,              // 36
	MSEPositionY,              // 40
	MSEHasOrientation,         // 48
	MSEHasGuidByte4,           // 20
	MSEHasGuidByte5,           // 21
	MSEZeroBit,                // 148
	MSEHasTimestamp,           // 32
	MSEZeroBit,                // 172
	MSEZeroBit,                // 149
	MSEHasUnkTime,             // 168
	MSEHasGuidByte3,           // 19
	MSEHasGuidByte1,           // 17
	MSEHasMovementFlags2,      // 28
	MSEHasMovementFlags,       // 24
	MSEHasGuidByte0,           // 16
	MSEHasGuidByte2,           // 18
	MSECounterCount,            // 152
	MSEHasTransportData,       // 104
	MSEHasGuidByte7,           // 23
	MSEHasPitch,               // 112
	MSEHasSplineElevation,     // 144
	MSEHasFallData,            // 140
	MSEHasGuidByte6,           // 22
	MSEHasTransportTime3,      // 100
	MSEHasTransportGuidByte5,  // 61
	MSEHasTransportGuidByte6,  // 62
	MSEHasTransportGuidByte2,  // 58
	MSEHasTransportGuidByte3,  // 59
	MSEHasTransportGuidByte4,  // 60
	MSEHasTransportGuidByte7,  // 63
	MSEHasTransportTime2,      // 92
	MSEHasTransportGuidByte0,  // 56
	MSEHasTransportGuidByte1,  // 57
	MSEMovementFlags,          // 24
	MSEMovementFlags2,         // 28
	MSEHasFallDirection,       // 136
	MSEGuidByte7,              // 23
	MSEGuidByte3,              // 19
	MSEGuidByte6,              // 22
	MSEGuidByte4,              // 20
	MSEGuidByte1,              // 17
	MSECounter,                 // 156
	MSEGuidByte5,              // 21
	MSEGuidByte0,              // 16
	MSEGuidByte2,              // 18
	MSEFallTime,               // 116
	MSEFallHorizontalSpeed,    // 132
	MSEFallCosAngle,           // 124
	MSEFallSinAngle,           // 128
	MSEFallVerticalSpeed,      // 120
	MSEPitch,                  // 112
	MSETransportPositionY,     // 68
	MSETransportGuidByte3,     // 59
	MSETransportPositionX,     // 64
	MSETransportOrientation,   // 76
	MSETransportGuidByte5,     // 61
	MSETransportTime2,         // 88
	MSETransportPositionZ,     // 72
	MSETransportGuidByte2,     // 58
	MSETransportGuidByte1,     // 57
	MSETransportGuidByte7,     // 63
	MSETransportGuidByte4,     // 60
	MSETransportGuidByte0,     // 56
	MSETransportTime3,         // 96
	MSETransportSeat,          // 80
	MSETransportGuidByte6,     // 62
	MSETransportTime,          // 84
	MSEOrientation,            // 48
	MSESplineElevation,        // 144
	MSECounter,                // 168
	MSETimestamp,              // 32
	MSEEnd
};

//5.4.0
MovementStatusElements const MovementStartTurnRightSequence[] =
{
	MSEPositionX,              // 36
	MSEPositionZ,              // 44
	MSEPositionY,              // 40
	MSEZeroBit,                // 148
	MSEZeroBit,                // 172
	MSEHasGuidByte1,           // 17
	MSEHasGuidByte0,           // 16
	MSEHasMovementFlags,       // 24
	MSEHasFallData,            // 140
	MSEHasPitch,               // 112
	MSEHasUnkTime,             // 168
	MSECounterCount,            // 152
	MSEHasSplineElevation,     // 144
	MSEHasMovementFlags2,      // 28
	MSEHasOrientation,         // 48
	MSEHasGuidByte2,           // 18
	MSEHasTimestamp,           // 32
	MSEHasGuidByte4,           // 20
	MSEHasGuidByte6,           // 22
	MSEHasGuidByte5,           // 21
	MSEHasGuidByte3,           // 19
	MSEZeroBit,                // 149
	MSEHasTransportData,       // 104
	MSEHasGuidByte7,           // 23
	MSEHasTransportGuidByte2,  // 58
	MSEHasTransportTime2,      // 92
	MSEHasTransportGuidByte6,  // 62
	MSEHasTransportGuidByte5,  // 61
	MSEHasTransportGuidByte3,  // 59
	MSEHasTransportGuidByte7,  // 63
	MSEHasTransportGuidByte4,  // 60
	MSEHasTransportTime3,      // 100
	MSEHasTransportGuidByte0,  // 56
	MSEHasTransportGuidByte1,  // 57
	MSEMovementFlags,          // 24
	MSEMovementFlags2,         // 28
	MSEHasFallDirection,       // 136
	MSEGuidByte5,              // 21
	MSEGuidByte1,              // 17
	MSEGuidByte3,              // 19
	MSEGuidByte0,              // 16
	MSEGuidByte4,              // 20
	MSEGuidByte2,              // 18
	MSEGuidByte6,              // 22
	MSECounter,                 // 156
	MSEGuidByte7,              // 23
	MSEFallSinAngle,           // 128
	MSEFallHorizontalSpeed,    // 132
	MSEFallCosAngle,           // 124
	MSEFallVerticalSpeed,      // 120
	MSEFallTime,               // 116
	MSEPitch,                  // 112
	MSETransportTime3,         // 96
	MSETransportGuidByte3,     // 59
	MSETransportTime2,         // 88
	MSETransportGuidByte7,     // 63
	MSETransportGuidByte1,     // 57
	MSETransportPositionX,     // 64
	MSETransportSeat,          // 80
	MSETransportGuidByte5,     // 61
	MSETransportGuidByte4,     // 60
	MSETransportGuidByte2,     // 58
	MSETransportGuidByte0,     // 56
	MSETransportPositionZ,     // 72
	MSETransportTime,          // 84
	MSETransportPositionY,     // 68
	MSETransportGuidByte6,     // 62
	MSETransportOrientation,   // 76
	MSEOrientation,            // 48
	MSETimestamp,              // 32
	MSESplineElevation,        // 144
	MSECounter,                // 168
	MSEEnd
};

//5.4.0
MovementStatusElements const MovementStopSequence[] =
{
	MSEPositionX,              // 36
	MSEPositionY,              // 40
	MSEPositionZ,              // 44
	MSEHasGuidByte5,           // 21
	MSEHasGuidByte2,           // 18
	MSEHasFallData,            // 140
	MSEHasGuidByte0,           // 16
	MSEZeroBit,                // 172
	MSEZeroBit,                // 148
	MSEHasUnkTime,             // 168
	MSEHasGuidByte1,           // 17
	MSECounterCount,            // 152
	MSEHasPitch,               // 112
	MSEHasGuidByte3,           // 19
	MSEHasGuidByte4,           // 20
	MSEHasTransportData,       // 104
	MSEZeroBit,                // 149
	MSEHasGuidByte6,           // 22
	MSEHasMovementFlags,       // 24
	MSEHasTimestamp,           // 32
	MSEHasMovementFlags2,      // 28
	MSEHasOrientation,         // 48
	MSEHasSplineElevation,     // 144
	MSEHasGuidByte7,           // 23
	MSEHasTransportTime2,      // 92
	MSEHasTransportGuidByte7,  // 63
	MSEHasTransportGuidByte4,  // 60
	MSEHasTransportGuidByte1,  // 57
	MSEHasTransportGuidByte0,  // 56
	MSEHasTransportGuidByte5,  // 61
	MSEHasTransportGuidByte2,  // 58
	MSEHasTransportGuidByte3,  // 59
	MSEHasTransportTime3,      // 100
	MSEHasTransportGuidByte6,  // 62
	MSEHasFallDirection,       // 136
	MSEMovementFlags2,         // 28
	MSEMovementFlags,          // 24
	MSEGuidByte0,              // 16
	MSEGuidByte3,              // 19
	MSECounter,                 // 156
	MSEGuidByte6,              // 22
	MSEGuidByte1,              // 17
	MSEGuidByte4,              // 20
	MSEGuidByte2,              // 18
	MSEGuidByte5,              // 21
	MSEGuidByte7,              // 23
	MSEOrientation,            // 48
	MSEFallVerticalSpeed,      // 120
	MSEFallHorizontalSpeed,    // 132
	MSEFallSinAngle,           // 128
	MSEFallCosAngle,           // 124
	MSEFallTime,               // 116
	MSESplineElevation,        // 144
	MSETransportPositionX,     // 64
	MSETransportTime,          // 84
	MSETransportGuidByte3,     // 59
	MSETransportOrientation,   // 76
	MSETransportPositionY,     // 68
	MSETransportGuidByte2,     // 58
	MSETransportGuidByte6,     // 62
	MSETransportGuidByte7,     // 63
	MSETransportGuidByte1,     // 57
	MSETransportGuidByte4,     // 60
	MSETransportTime3,         // 96
	MSETransportGuidByte0,     // 56
	MSETransportSeat,          // 80
	MSETransportPositionZ,     // 72
	MSETransportGuidByte5,     // 61
	MSETransportTime2,         // 88
	MSECounter,                // 168
	MSEPitch,                  // 112
	MSETimestamp,              // 32
	MSEEnd
};

//5.4.0
MovementStatusElements const MovementStopStrafeSequence[] =
{
	MSEPositionZ,              // 44
	MSEPositionX,              // 36
	MSEPositionY,              // 40
	MSEHasFallData,            // 140
	MSEHasOrientation,         // 48
	MSEHasSplineElevation,     // 144
	MSEHasTimestamp,           // 32
	MSEHasMovementFlags,       // 24
	MSEHasUnkTime,             // 168
	MSEHasGuidByte6,           // 22
	MSEHasTransportData,       // 104
	MSEZeroBit,                // 172
	MSEHasMovementFlags2,      // 28
	MSEHasGuidByte4,           // 20
	MSEHasPitch,               // 112
	MSEHasGuidByte5,           // 21
	MSEHasGuidByte3,           // 19
	MSEHasGuidByte2,           // 18
	MSECounterCount,            // 152
	MSEZeroBit,                // 149
	MSEHasGuidByte7,           // 23
	MSEHasGuidByte0,           // 16
	MSEZeroBit,                // 148
	MSEHasGuidByte1,           // 17
	MSEHasTransportGuidByte7,  // 63
	MSEHasTransportTime3,      // 100
	MSEHasTransportGuidByte3,  // 59
	MSEHasTransportGuidByte1,  // 57
	MSEHasTransportGuidByte6,  // 62
	MSEHasTransportTime2,      // 92
	MSEHasTransportGuidByte2,  // 58
	MSEHasTransportGuidByte5,  // 61
	MSEHasTransportGuidByte4,  // 60
	MSEHasTransportGuidByte0,  // 56
	MSEMovementFlags2,         // 28
	MSEHasFallDirection,       // 136
	MSEMovementFlags,          // 24
	MSEGuidByte5,              // 21
	MSEGuidByte3,              // 19
	MSECounter,                 // 156
	MSEGuidByte2,              // 18
	MSEGuidByte0,              // 16
	MSEGuidByte1,              // 17
	MSEGuidByte6,              // 22
	MSEGuidByte4,              // 20
	MSEGuidByte7,              // 23
	MSETransportGuidByte0,     // 56
	MSETransportTime3,         // 96
	MSETransportGuidByte1,     // 57
	MSETransportGuidByte6,     // 62
	MSETransportTime,          // 84
	MSETransportPositionY,     // 68
	MSETransportPositionZ,     // 72
	MSETransportGuidByte4,     // 60
	MSETransportTime2,         // 88
	MSETransportGuidByte3,     // 59
	MSETransportSeat,          // 80
	MSETransportPositionX,     // 64
	MSETransportGuidByte2,     // 58
	MSETransportGuidByte7,     // 63
	MSETransportGuidByte5,     // 61
	MSETransportOrientation,   // 76
	MSEOrientation,            // 48
	MSESplineElevation,        // 144
	MSETimestamp,              // 32
	MSEFallCosAngle,           // 124
	MSEFallSinAngle,           // 128
	MSEFallHorizontalSpeed,    // 132
	MSEFallTime,               // 116
	MSEFallVerticalSpeed,      // 120
	MSEPitch,                  // 112
	MSECounter,                // 168
	MSEEnd
};

//5.4.0
MovementStatusElements const MovementStopTurnSequence[] =
{
	MSEPositionX,              // 36
	MSEPositionZ,              // 44
	MSEPositionY,              // 40
	MSEHasTransportData,       // 104
	MSECounterCount,            // 152
	MSEZeroBit,                // 149
	MSEHasGuidByte4,           // 20
	MSEHasGuidByte5,           // 21
	MSEHasUnkTime,             // 168
	MSEHasGuidByte3,           // 19
	MSEZeroBit,                // 172
	MSEHasFallData,            // 140
	MSEHasGuidByte0,           // 16
	MSEHasGuidByte1,           // 17
	MSEHasPitch,               // 112
	MSEHasGuidByte6,           // 22
	MSEHasMovementFlags,       // 24
	MSEHasGuidByte2,           // 18
	MSEZeroBit,                // 148
	MSEHasMovementFlags2,      // 28
	MSEHasSplineElevation,     // 144
	MSEHasOrientation,         // 48
	MSEHasGuidByte7,           // 23
	MSEHasTimestamp,           // 32
	MSEMovementFlags2,         // 28
	MSEHasTransportGuidByte1,  // 57
	MSEHasTransportTime3,      // 100
	MSEHasTransportTime2,      // 92
	MSEHasTransportGuidByte3,  // 59
	MSEHasTransportGuidByte6,  // 62
	MSEHasTransportGuidByte2,  // 58
	MSEHasTransportGuidByte0,  // 56
	MSEHasTransportGuidByte5,  // 61
	MSEHasTransportGuidByte7,  // 63
	MSEHasTransportGuidByte4,  // 60
	MSEMovementFlags,          // 24
	MSEHasFallDirection,       // 136
	MSEGuidByte2,              // 18
	MSEGuidByte3,              // 19
	MSEGuidByte6,              // 22
	MSECounter,                 // 156
	MSEGuidByte0,              // 16
	MSEGuidByte5,              // 21
	MSEGuidByte4,              // 20
	MSEGuidByte7,              // 23
	MSEGuidByte1,              // 17
	MSETransportTime,          // 84
	MSETransportTime3,         // 96
	MSETransportSeat,          // 80
	MSETransportPositionY,     // 68
	MSETransportPositionX,     // 64
	MSETransportTime2,         // 88
	MSETransportGuidByte4,     // 60
	MSETransportGuidByte3,     // 59
	MSETransportOrientation,   // 76
	MSETransportGuidByte0,     // 56
	MSETransportPositionZ,     // 72
	MSETransportGuidByte6,     // 62
	MSETransportGuidByte7,     // 63
	MSETransportGuidByte5,     // 61
	MSETransportGuidByte1,     // 57
	MSETransportGuidByte2,     // 58
	MSEOrientation,            // 48
	MSETimestamp,              // 32
	MSEFallSinAngle,           // 128
	MSEFallCosAngle,           // 124
	MSEFallHorizontalSpeed,    // 132
	MSEFallVerticalSpeed,      // 120
	MSEFallTime,               // 116
	MSECounter,                // 168
	MSESplineElevation,        // 144
	MSEPitch,                  // 112
	MSEEnd
};

//5.4.0
MovementStatusElements const MovementStartAscendSequence[] =
{
	MSEPositionY,              // 40
	MSEPositionX,              // 36
	MSEPositionZ,              // 44
	MSEHasOrientation,         // 48
	MSEHasGuidByte3,           // 19
	MSEHasTransportData,       // 104
	MSEHasMovementFlags,       // 24
	MSEZeroBit,                // 172
	MSEHasGuidByte0,           // 16
	MSEHasGuidByte4,           // 20
	MSEHasTimestamp,           // 32
	MSEHasGuidByte7,           // 23
	MSEZeroBit,                // 149
	MSEHasPitch,               // 112
	MSEHasGuidByte5,           // 21
	MSEHasMovementFlags2,      // 28
	MSEZeroBit,                // 148
	MSEHasGuidByte6,           // 22
	MSEHasGuidByte2,           // 18
	MSEHasUnkTime,             // 168
	MSECounterCount,            // 152
	MSEHasGuidByte1,           // 17
	MSEHasSplineElevation,     // 144
	MSEHasFallData,            // 140
	MSEHasTransportGuidByte4,  // 60
	MSEHasTransportGuidByte0,  // 56
	MSEHasTransportGuidByte3,  // 59
	MSEHasTransportGuidByte5,  // 61
	MSEHasTransportTime2,      // 92
	MSEHasTransportGuidByte1,  // 57
	MSEHasTransportTime3,      // 100
	MSEHasTransportGuidByte6,  // 62
	MSEHasTransportGuidByte2,  // 58
	MSEHasTransportGuidByte7,  // 63
	MSEHasFallDirection,       // 136
	MSEMovementFlags2,         // 28
	MSEMovementFlags,          // 24
	MSEGuidByte2,              // 18
	MSEGuidByte5,              // 21
	MSECounter,                 // 156
	MSEGuidByte1,              // 17
	MSEGuidByte0,              // 16
	MSEGuidByte4,              // 20
	MSEGuidByte7,              // 23
	MSEGuidByte6,              // 22
	MSEGuidByte3,              // 19
	MSEOrientation,            // 48
	MSETimestamp,              // 32
	MSETransportGuidByte3,     // 59
	MSETransportTime,          // 84
	MSETransportPositionY,     // 68
	MSETransportOrientation,   // 76
	MSETransportGuidByte6,     // 62
	MSETransportTime3,         // 96
	MSETransportPositionX,     // 64
	MSETransportGuidByte2,     // 58
	MSETransportTime2,         // 88
	MSETransportGuidByte1,     // 57
	MSETransportGuidByte7,     // 63
	MSETransportPositionZ,     // 72
	MSETransportSeat,          // 80
	MSETransportGuidByte0,     // 56
	MSETransportGuidByte4,     // 60
	MSETransportGuidByte5,     // 61
	MSESplineElevation,        // 144
	MSEFallVerticalSpeed,      // 120
	MSEFallSinAngle,           // 128
	MSEFallCosAngle,           // 124
	MSEFallHorizontalSpeed,    // 132
	MSEFallTime,               // 116
	MSEPitch,                  // 112
	MSECounter,                // 168
	MSEEnd
};

//5.4.0
MovementStatusElements const MovementStartDescendSequence[] =
{
	MSEPositionX,              // 36
	MSEPositionY,              // 40
	MSEPositionZ,              // 44
	MSEHasFallData,            // 140
	MSEHasMovementFlags,       // 24
	MSEHasGuidByte7,           // 23
	MSEHasGuidByte0,           // 16
	MSEHasGuidByte4,           // 20
	MSEHasMovementFlags2,      // 28
	MSEHasPitch,               // 112
	MSEHasGuidByte6,           // 22
	MSEHasGuidByte2,           // 18
	MSEZeroBit,                // 148
	MSEHasUnkTime,             // 168
	MSECounterCount,            // 152
	MSEHasTransportData,       // 104
	MSEHasOrientation,         // 48
	MSEHasGuidByte1,           // 17
	MSEZeroBit,                // 149
	MSEZeroBit,                // 172
	MSEHasGuidByte3,           // 19
	MSEHasGuidByte5,           // 21
	MSEHasSplineElevation,     // 144
	MSEHasTimestamp,           // 32
	MSEHasTransportGuidByte0,  // 56
	MSEHasTransportTime3,      // 100
	MSEHasTransportGuidByte7,  // 63
	MSEHasTransportTime2,      // 92
	MSEHasTransportGuidByte1,  // 57
	MSEHasTransportGuidByte4,  // 60
	MSEHasTransportGuidByte5,  // 61
	MSEHasTransportGuidByte3,  // 59
	MSEHasTransportGuidByte6,  // 62
	MSEHasTransportGuidByte2,  // 58
	MSEMovementFlags2,         // 28
	MSEMovementFlags,          // 24
	MSEHasFallDirection,       // 136
	MSEGuidByte4,              // 20
	MSEGuidByte7,              // 23
	MSEGuidByte1,              // 17
	MSEGuidByte3,              // 19
	MSECounter,                 // 156
	MSEGuidByte2,              // 18
	MSEGuidByte6,              // 22
	MSEGuidByte0,              // 16
	MSEGuidByte5,              // 21
	MSETransportPositionX,     // 64
	MSETransportGuidByte0,     // 56
	MSETransportGuidByte3,     // 59
	MSETransportGuidByte7,     // 63
	MSETransportSeat,          // 80
	MSETransportGuidByte5,     // 61
	MSETransportGuidByte1,     // 57
	MSETransportPositionY,     // 68
	MSETransportTime3,         // 96
	MSETransportTime,          // 84
	MSETransportGuidByte4,     // 60
	MSETransportTime2,         // 88
	MSETransportOrientation,   // 76
	MSETransportPositionZ,     // 72
	MSETransportGuidByte2,     // 58
	MSETransportGuidByte6,     // 62
	MSEFallTime,               // 116
	MSEFallCosAngle,           // 124
	MSEFallHorizontalSpeed,    // 132
	MSEFallSinAngle,           // 128
	MSEFallVerticalSpeed,      // 120
	MSEPitch,                  // 112
	MSECounter,                // 168
	MSESplineElevation,        // 144
	MSEOrientation,            // 48
	MSETimestamp,              // 32
	MSEEnd
};

//5.4.0
MovementStatusElements const MovementStartSwimSequence[] =
{
	MSEPositionX,              // 36
	MSEPositionY,              // 40
	MSEPositionZ,              // 44
	MSEHasSplineElevation,     // 144
	MSEHasTransportData,       // 104
	MSEHasGuidByte2,           // 18
	MSEZeroBit,                // 172
	MSEHasMovementFlags2,      // 28
	MSECounterCount,            // 152
	MSEHasPitch,               // 112
	MSEHasTimestamp,           // 32
	MSEHasGuidByte3,           // 19
	MSEZeroBit,                // 149
	MSEHasGuidByte6,           // 22
	MSEHasGuidByte1,           // 17
	MSEHasFallData,            // 140
	MSEHasUnkTime,             // 168
	MSEZeroBit,                // 148
	MSEHasGuidByte7,           // 23
	MSEHasGuidByte0,           // 16
	MSEHasOrientation,         // 48
	MSEHasGuidByte5,           // 21
	MSEHasMovementFlags,       // 24
	MSEHasGuidByte4,           // 20
	MSEHasTransportTime2,      // 92
	MSEHasTransportGuidByte2,  // 58
	MSEHasTransportGuidByte7,  // 63
	MSEHasTransportGuidByte6,  // 62
	MSEHasTransportGuidByte5,  // 61
	MSEHasTransportGuidByte1,  // 57
	MSEHasTransportGuidByte4,  // 60
	MSEHasTransportTime3,      // 100
	MSEHasTransportGuidByte0,  // 56
	MSEHasTransportGuidByte3,  // 59
	MSEMovementFlags,          // 24
	MSEHasFallDirection,       // 136
	MSEMovementFlags2,         // 28
	MSEGuidByte5,              // 21
	MSEGuidByte0,              // 16
	MSECounter,                 // 156
	MSEGuidByte7,              // 23
	MSEGuidByte3,              // 19
	MSEGuidByte4,              // 20
	MSEGuidByte1,              // 17
	MSEGuidByte6,              // 22
	MSEGuidByte2,              // 18
	MSETransportGuidByte3,     // 59
	MSETransportPositionX,     // 64
	MSETransportGuidByte7,     // 63
	MSETransportGuidByte0,     // 56
	MSETransportPositionY,     // 68
	MSETransportSeat,          // 80
	MSETransportTime2,         // 88
	MSETransportGuidByte6,     // 62
	MSETransportGuidByte4,     // 60
	MSETransportGuidByte1,     // 57
	MSETransportGuidByte2,     // 58
	MSETransportPositionZ,     // 72
	MSETransportTime,          // 84
	MSETransportOrientation,   // 76
	MSETransportTime3,         // 96
	MSETransportGuidByte5,     // 61
	MSEFallCosAngle,           // 124
	MSEFallSinAngle,           // 128
	MSEFallHorizontalSpeed,    // 132
	MSEFallTime,               // 116
	MSEFallVerticalSpeed,      // 120
	MSETimestamp,              // 32
	MSESplineElevation,        // 144
	MSEOrientation,            // 48
	MSECounter,                // 168
	MSEPitch,                  // 112
	MSEEnd
};

//5.4.0
MovementStatusElements const MovementStopSwimSequence[] =
{
	MSEPositionX,              // 36
	MSEPositionZ,              // 44
	MSEPositionY,              // 40
	MSEHasPitch,               // 112
	MSEHasGuidByte6,           // 22
	MSEHasOrientation,         // 48
	MSEZeroBit,                // 172
	MSEZeroBit,                // 149
	MSEZeroBit,                // 148
	MSEHasUnkTime,             // 168
	MSEHasGuidByte4,           // 20
	MSEHasMovementFlags2,      // 28
	MSEHasTransportData,       // 104
	MSEHasFallData,            // 140
	MSEHasGuidByte1,           // 17
	MSECounterCount,            // 152
	MSEHasMovementFlags,       // 24
	MSEHasGuidByte7,           // 23
	MSEHasGuidByte0,           // 16
	MSEHasTimestamp,           // 32
	MSEHasGuidByte3,           // 19
	MSEHasGuidByte5,           // 21
	MSEHasSplineElevation,     // 144
	MSEHasGuidByte2,           // 18
	MSEHasTransportGuidByte1,  // 57
	MSEHasTransportTime2,      // 92
	MSEHasTransportGuidByte5,  // 61
	MSEHasTransportGuidByte2,  // 58
	MSEHasTransportGuidByte4,  // 60
	MSEHasTransportGuidByte6,  // 62
	MSEHasTransportGuidByte7,  // 63
	MSEHasTransportGuidByte3,  // 59
	MSEHasTransportTime3,      // 100
	MSEHasTransportGuidByte0,  // 56
	MSEHasFallDirection,       // 136
	MSEMovementFlags,          // 24
	MSEMovementFlags2,         // 28
	MSEGuidByte7,              // 23
	MSEGuidByte6,              // 22
	MSEGuidByte1,              // 17
	MSEGuidByte5,              // 21
	MSEGuidByte4,              // 20
	MSEGuidByte3,              // 19
	MSECounter,                 // 156
	MSEGuidByte0,              // 16
	MSEGuidByte2,              // 18
	MSETransportTime,          // 84
	MSETransportGuidByte1,     // 57
	MSETransportGuidByte2,     // 58
	MSETransportPositionZ,     // 72
	MSETransportPositionX,     // 64
	MSETransportPositionY,     // 68
	MSETransportGuidByte0,     // 56
	MSETransportGuidByte6,     // 62
	MSETransportGuidByte3,     // 59
	MSETransportSeat,          // 80
	MSETransportOrientation,   // 76
	MSETransportGuidByte7,     // 63
	MSETransportGuidByte4,     // 60
	MSETransportGuidByte5,     // 61
	MSETransportTime2,         // 88
	MSETransportTime3,         // 96
	MSEFallCosAngle,           // 124
	MSEFallHorizontalSpeed,    // 132
	MSEFallSinAngle,           // 128
	MSEFallVerticalSpeed,      // 120
	MSEFallTime,               // 116
	MSESplineElevation,        // 144
	MSEPitch,                  // 112
	MSETimestamp,              // 32
	MSECounter,                // 168
	MSEOrientation,            // 48
	MSEEnd
};

//5.4.0
MovementStatusElements const MovementStopAscendSequence[] =
{
	MSEPositionZ,              // 44
	MSEPositionX,              // 36
	MSEPositionY,              // 40
	MSEHasOrientation,         // 48
	MSEHasGuidByte0,           // 16
	MSEHasGuidByte3,           // 19
	MSEHasGuidByte7,           // 23
	MSEHasGuidByte2,           // 18
	MSEHasGuidByte6,           // 22
	MSEHasMovementFlags2,      // 28
	MSEHasTimestamp,           // 32
	MSEHasUnkTime,             // 168
	MSEHasTransportData,       // 104
	MSEHasPitch,               // 112
	MSEZeroBit,                // 148
	MSEZeroBit,                // 172
	MSEHasGuidByte4,           // 20
	MSEZeroBit,                // 149
	MSEHasGuidByte5,           // 21
	MSECounterCount,            // 152
	MSEHasFallData,            // 140
	MSEHasMovementFlags,       // 24
	MSEHasGuidByte1,           // 17
	MSEHasSplineElevation,     // 144
	MSEHasTransportTime2,      // 92
	MSEHasTransportGuidByte0,  // 56
	MSEHasTransportGuidByte5,  // 61
	MSEHasTransportGuidByte4,  // 60
	MSEHasTransportGuidByte6,  // 62
	MSEHasTransportGuidByte2,  // 58
	MSEHasTransportGuidByte1,  // 57
	MSEHasTransportTime3,      // 100
	MSEHasTransportGuidByte3,  // 59
	MSEHasTransportGuidByte7,  // 63
	MSEMovementFlags2,         // 28
	MSEMovementFlags,          // 24
	MSEHasFallDirection,       // 136
	MSEGuidByte0,              // 16
	MSECounter,                 // 156
	MSEGuidByte4,              // 20
	MSEGuidByte5,              // 21
	MSEGuidByte1,              // 17
	MSEGuidByte7,              // 23
	MSEGuidByte6,              // 22
	MSEGuidByte3,              // 19
	MSEGuidByte2,              // 18
	MSETransportGuidByte5,     // 61
	MSETransportPositionY,     // 68
	MSETransportGuidByte4,     // 60
	MSETransportGuidByte7,     // 63
	MSETransportGuidByte1,     // 57
	MSETransportGuidByte3,     // 59
	MSETransportTime2,         // 88
	MSETransportPositionX,     // 64
	MSETransportOrientation,   // 76
	MSETransportGuidByte0,     // 56
	MSETransportGuidByte2,     // 58
	MSETransportPositionZ,     // 72
	MSETransportTime3,         // 96
	MSETransportTime,          // 84
	MSETransportSeat,          // 80
	MSETransportGuidByte6,     // 62
	MSEFallCosAngle,           // 124
	MSEFallHorizontalSpeed,    // 132
	MSEFallSinAngle,           // 128
	MSEFallTime,               // 116
	MSEFallVerticalSpeed,      // 120
	MSETimestamp,              // 32
	MSESplineElevation,        // 144
	MSEPitch,                  // 112
	MSECounter,                // 168
	MSEOrientation,            // 48
	MSEEnd
};

//5.4.0
MovementStatusElements const MovementStopPitchSequence[] =
{
	MSEPositionY,              // 40
	MSEPositionX,              // 36
	MSEPositionZ,              // 44
	MSEHasFallData,            // 140
	MSEHasSplineElevation,     // 144
	MSEHasGuidByte0,           // 16
	MSEHasTimestamp,           // 32
	MSEZeroBit,                // 148
	MSEHasGuidByte2,           // 18
	MSECounterCount,            // 152
	MSEHasOrientation,         // 48
	MSEHasMovementFlags,       // 24
	MSEHasPitch,               // 112
	MSEHasGuidByte3,           // 19
	MSEHasGuidByte7,           // 23
	MSEHasGuidByte5,           // 21
	MSEHasMovementFlags2,      // 28
	MSEZeroBit,                // 172
	MSEHasUnkTime,             // 168
	MSEHasTransportData,       // 104
	MSEHasGuidByte6,           // 22
	MSEHasGuidByte4,           // 20
	MSEZeroBit,                // 149
	MSEHasGuidByte1,           // 17
	MSEHasTransportGuidByte4,  // 60
	MSEHasTransportGuidByte5,  // 61
	MSEHasTransportTime3,      // 100
	MSEHasTransportGuidByte6,  // 62
	MSEHasTransportGuidByte3,  // 59
	MSEHasTransportGuidByte0,  // 56
	MSEHasTransportGuidByte7,  // 63
	MSEHasTransportGuidByte1,  // 57
	MSEHasTransportTime2,      // 92
	MSEHasTransportGuidByte2,  // 58
	MSEMovementFlags2,         // 28
	MSEMovementFlags,          // 24
	MSEHasFallDirection,       // 136
	MSEGuidByte0,              // 16
	MSEGuidByte6,              // 22
	MSEGuidByte7,              // 23
	MSEGuidByte1,              // 17
	MSECounter,                 // 156
	MSEGuidByte5,              // 21
	MSEGuidByte3,              // 19
	MSEGuidByte4,              // 20
	MSEGuidByte2,              // 18
	MSEFallSinAngle,           // 128
	MSEFallHorizontalSpeed,    // 132
	MSEFallCosAngle,           // 124
	MSEFallTime,               // 116
	MSEFallVerticalSpeed,      // 120
	MSETransportGuidByte1,     // 57
	MSETransportPositionX,     // 64
	MSETransportPositionZ,     // 72
	MSETransportPositionY,     // 68
	MSETransportGuidByte5,     // 61
	MSETransportGuidByte0,     // 56
	MSETransportTime2,         // 88
	MSETransportGuidByte6,     // 62
	MSETransportGuidByte2,     // 58
	MSETransportGuidByte3,     // 59
	MSETransportSeat,          // 80
	MSETransportTime3,         // 96
	MSETransportTime,          // 84
	MSETransportGuidByte4,     // 60
	MSETransportGuidByte7,     // 63
	MSETransportOrientation,   // 76
	MSEPitch,                  // 112
	MSETimestamp,              // 32
	MSESplineElevation,        // 144
	MSEOrientation,            // 48
	MSECounter,                // 168
	MSEEnd
};

//5.4.0
MovementStatusElements const MovementStartPitchDownSequence[] =
{
	MSEPositionZ,              // 44
	MSEPositionY,              // 40
	MSEPositionX,              // 36
	MSEHasGuidByte2,           // 18
	MSEHasGuidByte7,           // 23
	MSEHasGuidByte3,           // 19
	MSEHasOrientation,         // 48
	MSEHasGuidByte5,           // 21
	MSEZeroBit,                // 172
	MSEHasUnkTime,             // 168
	MSEZeroBit,                // 148
	MSEHasMovementFlags,       // 24
	MSEHasGuidByte4,           // 20
	MSEHasGuidByte1,           // 17
	MSEHasSplineElevation,     // 144
	MSEHasFallData,            // 140
	MSEZeroBit,                // 149
	MSEHasTransportData,       // 104
	MSEHasTimestamp,           // 32
	MSEHasMovementFlags2,      // 28
	MSECounterCount,            // 152
	MSEHasGuidByte6,           // 22
	MSEHasGuidByte0,           // 16
	MSEHasPitch,               // 112
	MSEHasTransportTime2,      // 92
	MSEHasTransportGuidByte2,  // 58
	MSEHasTransportGuidByte6,  // 62
	MSEHasTransportGuidByte3,  // 59
	MSEHasTransportGuidByte7,  // 63
	MSEHasTransportGuidByte5,  // 61
	MSEHasTransportGuidByte4,  // 60
	MSEHasTransportTime3,      // 100
	MSEHasTransportGuidByte1,  // 57
	MSEHasTransportGuidByte0,  // 56
	MSEMovementFlags,          // 24
	MSEMovementFlags2,         // 28
	MSEHasFallDirection,       // 136
	MSEGuidByte6,              // 22
	MSEGuidByte3,              // 19
	MSEGuidByte5,              // 21
	MSEGuidByte0,              // 16
	MSEGuidByte4,              // 20
	MSECounter,                 // 156
	MSEGuidByte7,              // 23
	MSEGuidByte2,              // 18
	MSEGuidByte1,              // 17
	MSEFallHorizontalSpeed,    // 132
	MSEFallCosAngle,           // 124
	MSEFallSinAngle,           // 128
	MSEFallTime,               // 116
	MSEFallVerticalSpeed,      // 120
	MSETransportOrientation,   // 76
	MSETransportGuidByte4,     // 60
	MSETransportGuidByte7,     // 63
	MSETransportPositionZ,     // 72
	MSETransportGuidByte0,     // 56
	MSETransportTime,          // 84
	MSETransportGuidByte6,     // 62
	MSETransportGuidByte1,     // 57
	MSETransportSeat,          // 80
	MSETransportGuidByte2,     // 58
	MSETransportGuidByte5,     // 61
	MSETransportPositionX,     // 64
	MSETransportTime3,         // 96
	MSETransportPositionY,     // 68
	MSETransportGuidByte3,     // 59
	MSETransportTime2,         // 88
	MSEOrientation,            // 48
	MSETimestamp,              // 32
	MSESplineElevation,        // 144
	MSECounter,                // 168
	MSEPitch,                  // 112
	MSEEnd
};

//5.4.0
MovementStatusElements const MovementStartPitchUpSequence[] =
{
	MSEPositionY,              // 40
	MSEPositionZ,              // 44
	MSEPositionX,              // 36
	MSEHasGuidByte0,           // 16
	MSEHasPitch,               // 112
	MSEHasGuidByte3,           // 19
	MSEZeroBit,                // 148
	MSEHasOrientation,         // 48
	MSEHasGuidByte5,           // 21
	MSEZeroBit,                // 149
	MSEHasGuidByte2,           // 18
	MSEHasGuidByte7,           // 23
	MSEHasGuidByte1,           // 17
	MSEHasFallData,            // 140
	MSEHasMovementFlags2,      // 28
	MSEHasTransportData,       // 104
	MSEHasUnkTime,             // 168
	MSEHasMovementFlags,       // 24
	MSEHasGuidByte6,           // 22
	MSECounterCount,            // 152
	MSEHasTimestamp,           // 32
	MSEHasGuidByte4,           // 20
	MSEZeroBit,                // 172
	MSEHasSplineElevation,     // 144
	MSEHasTransportGuidByte5,  // 61
	MSEHasTransportGuidByte1,  // 57
	MSEHasTransportTime2,      // 92
	MSEHasTransportGuidByte4,  // 60
	MSEHasTransportGuidByte2,  // 58
	MSEHasTransportGuidByte6,  // 62
	MSEHasTransportGuidByte0,  // 56
	MSEHasTransportTime3,      // 100
	MSEHasTransportGuidByte7,  // 63
	MSEHasTransportGuidByte3,  // 59
	MSEMovementFlags2,         // 28
	MSEMovementFlags,          // 24
	MSEHasFallDirection,       // 136
	MSEGuidByte6,              // 22
	MSECounter,                 // 156
	MSEGuidByte0,              // 16
	MSEGuidByte5,              // 21
	MSEGuidByte7,              // 23
	MSEGuidByte1,              // 17
	MSEGuidByte3,              // 19
	MSEGuidByte4,              // 20
	MSEGuidByte2,              // 18
	MSETransportSeat,          // 80
	MSETransportGuidByte3,     // 59
	MSETransportTime3,         // 96
	MSETransportGuidByte2,     // 58
	MSETransportGuidByte7,     // 63
	MSETransportGuidByte0,     // 56
	MSETransportPositionY,     // 68
	MSETransportGuidByte4,     // 60
	MSETransportGuidByte5,     // 61
	MSETransportTime2,         // 88
	MSETransportGuidByte1,     // 57
	MSETransportPositionX,     // 64
	MSETransportOrientation,   // 76
	MSETransportGuidByte6,     // 62
	MSETransportTime,          // 84
	MSETransportPositionZ,     // 72
	MSEPitch,                  // 112
	MSEOrientation,            // 48
	MSESplineElevation,        // 144
	MSEFallVerticalSpeed,      // 120
	MSEFallHorizontalSpeed,    // 132
	MSEFallSinAngle,           // 128
	MSEFallCosAngle,           // 124
	MSEFallTime,               // 116
	MSECounter,                // 168
	MSETimestamp,              // 32
	MSEEnd
};

//5.4.0
MovementStatusElements const MoveChngTransport[]=
{
	MSEPositionX,              // 36
	MSEPositionY,              // 40
	MSEPositionZ,              // 44
	MSEHasGuidByte1,           // 17
	MSEHasPitch,               // 112
	MSEHasSplineElevation,     // 144
	MSEHasGuidByte4,           // 20
	MSEHasUnkTime,             // 168
	MSEHasGuidByte5,           // 21
	MSECounterCount,            // 152
	MSEZeroBit,                // 172
	MSEHasGuidByte6,           // 22
	MSEZeroBit,                // 148
	MSEHasGuidByte7,           // 23
	MSEHasGuidByte0,           // 16
	MSEHasTransportData,       // 104
	MSEHasMovementFlags,       // 24
	MSEZeroBit,                // 149
	MSEHasMovementFlags2,      // 28
	MSEHasGuidByte2,           // 18
	MSEHasGuidByte3,           // 19
	MSEHasTimestamp,           // 32
	MSEHasFallData,            // 140
	MSEHasOrientation,         // 48
	MSEHasTransportTime3,      // 100
	MSEHasTransportGuidByte5,  // 61
	MSEHasTransportGuidByte6,  // 62
	MSEHasTransportGuidByte3,  // 59
	MSEHasTransportGuidByte2,  // 58
	MSEHasTransportGuidByte4,  // 60
	MSEHasTransportTime2,      // 92
	MSEHasTransportGuidByte1,  // 57
	MSEHasTransportGuidByte7,  // 63
	MSEHasTransportGuidByte0,  // 56
	MSEMovementFlags,          // 24
	MSEHasFallDirection,       // 136
	MSEMovementFlags2,         // 28
	MSEGuidByte5,              // 21
	MSEGuidByte2,              // 18
	MSECounter,                 // 156
	MSEGuidByte6,              // 22
	MSEGuidByte3,              // 19
	MSEGuidByte0,              // 16
	MSEGuidByte4,              // 20
	MSEGuidByte7,              // 23
	MSEGuidByte1,              // 17
	MSEFallVerticalSpeed,      // 120
	MSEFallSinAngle,           // 128
	MSEFallHorizontalSpeed,    // 132
	MSEFallCosAngle,           // 124
	MSEFallTime,               // 116
	MSETransportGuidByte6,     // 62
	MSETransportPositionZ,     // 72
	MSETransportGuidByte5,     // 61
	MSETransportGuidByte4,     // 60
	MSETransportTime3,         // 96
	MSETransportGuidByte3,     // 59
	MSETransportTime,          // 84
	MSETransportGuidByte2,     // 58
	MSETransportTime2,         // 88
	MSETransportGuidByte0,     // 56
	MSETransportPositionY,     // 68
	MSETransportGuidByte1,     // 57
	MSETransportSeat,          // 80
	MSETransportOrientation,   // 76
	MSETransportGuidByte7,     // 63
	MSETransportPositionX,     // 64
	MSEOrientation,            // 48
	MSESplineElevation,        // 144
	MSECounter,                // 168
	MSEPitch,                  // 112
	MSETimestamp,              // 32
	MSEEnd
};

//5.4.0
MovementStatusElements const MoveSplineDone[] =
{
	MSECounter,                // 176
	MSEPositionZ,              // 44
	MSEPositionY,              // 40
	MSEPositionX,              // 36
	MSEHasGuidByte7,           // 23
	MSEHasMovementFlags2,      // 28
	MSEHasSplineElevation,     // 144
	MSEHasMovementFlags,       // 24
	MSEHasGuidByte3,           // 19
	MSEZeroBit,                // 172
	MSEHasGuidByte0,           // 16
	MSEHasPitch,               // 112
	MSEZeroBit,                // 149
	MSEHasGuidByte1,           // 17
	MSEZeroBit,                // 148
	MSEHasGuidByte2,           // 18
	MSEHasUnkTime,             // 168
	MSEHasGuidByte4,           // 20
	MSEHasTransportData,       // 104
	MSEHasGuidByte6,           // 22
	MSEHasGuidByte5,           // 21
	MSECounterCount,            // 152
	MSEHasOrientation,         // 48
	MSEHasTimestamp,           // 32
	MSEHasFallData,            // 140
	MSEHasTransportGuidByte2,  // 58
	MSEHasTransportTime3,      // 100
	MSEHasTransportTime2,      // 92
	MSEHasTransportGuidByte1,  // 57
	MSEHasTransportGuidByte4,  // 60
	MSEHasTransportGuidByte3,  // 59
	MSEHasTransportGuidByte7,  // 63
	MSEHasTransportGuidByte5,  // 61
	MSEHasTransportGuidByte0,  // 56
	MSEHasTransportGuidByte6,  // 62
	MSEMovementFlags2,         // 28
	MSEMovementFlags,          // 24
	MSEHasFallDirection,       // 136
	MSEGuidByte6,              // 22
	MSECounter,                 // 156
	MSEGuidByte1,              // 17
	MSEGuidByte5,              // 21
	MSEGuidByte0,              // 16
	MSEGuidByte7,              // 23
	MSEGuidByte4,              // 20
	MSEGuidByte2,              // 18
	MSEGuidByte3,              // 19
	MSESplineElevation,        // 144
	MSETransportGuidByte3,     // 59
	MSETransportOrientation,   // 76
	MSETransportGuidByte2,     // 58
	MSETransportGuidByte5,     // 61
	MSETransportGuidByte1,     // 57
	MSETransportPositionX,     // 64
	MSETransportGuidByte6,     // 62
	MSETransportSeat,          // 80
	MSETransportTime3,         // 96
	MSETransportGuidByte4,     // 60
	MSETransportGuidByte7,     // 63
	MSETransportGuidByte0,     // 56
	MSETransportPositionY,     // 68
	MSETransportTime2,         // 88
	MSETransportPositionZ,     // 72
	MSETransportTime,          // 84
	MSEFallSinAngle,           // 128
	MSEFallCosAngle,           // 124
	MSEFallHorizontalSpeed,    // 132
	MSEFallVerticalSpeed,      // 120
	MSEFallTime,               // 116
	MSECounter,                // 168
	MSEOrientation,            // 48
	MSETimestamp,              // 32
	MSEPitch,                  // 112
	MSEEnd
};

// 5.1.0 16357
MovementStatusElements const MoveNotActiveMover[] =
{
    MSEPositionZ,
    MSEPositionX,
    MSEPositionY,
    MSEHasMovementFlags2,
    MSEHasTransportData,
    MSEHasGuidByte6,
    MSEHasSplineElevation,
    MSEHasGuidByte3,
    MSEZeroBit,
    MSEHasTimestamp,
    MSEHasGuidByte0,
    MSEHasOrientation,
    MSEHasGuidByte5,
    MSEHasPitch,
    MSEHasGuidByte1,
    MSEHasGuidByte4,
    MSEHasGuidByte7,
    MSEHasSpline,
    MSEHasGuidByte2,
    MSEHasFallData,
    MSEHasMovementFlags,

    MSEHasTransportGuidByte4,
    MSEHasTransportGuidByte0,
    MSEHasTransportGuidByte1,
    MSEHasTransportGuidByte6,
    MSEHasTransportGuidByte2,
    MSEHasTransportTime3,
    MSEHasTransportGuidByte5,
    MSEHasTransportGuidByte7,
    MSEHasTransportTime2,
    MSEHasTransportGuidByte3,

    MSEHasFallDirection,
    MSEMovementFlags,
    MSEMovementFlags2,

    MSEGuidByte1,
    MSEGuidByte0,
    MSEGuidByte4,
    MSEGuidByte2,
    MSEGuidByte7,
    MSEGuidByte5,
    MSEGuidByte6,
    MSEGuidByte3,

    MSEFallVerticalSpeed,
    MSEFallCosAngle,
    MSEFallSinAngle,
    MSEFallHorizontalSpeed,
    MSEFallTime,

    MSETransportTime3,
    MSETransportGuidByte1,
    MSETransportTime2,
    MSETransportOrientation,
    MSETransportGuidByte0,
    MSETransportSeat,
    MSETransportGuidByte4,
    MSETransportGuidByte6,
    MSETransportGuidByte3,
    MSETransportGuidByte5,
    MSETransportPositionY,
    MSETransportPositionX,
    MSETransportGuidByte2,
    MSETransportPositionZ,
    MSETransportGuidByte7,
    MSETransportTime,

    MSETimestamp,
    MSESplineElevation,
    MSEPitch,
    MSEOrientation,

    MSEEnd,
};
// 5.4.0
MovementStatusElements const MoveSetCanFly[] =
{
	MSEHasGuidByte6,
	MSEHasGuidByte1,
	MSEHasGuidByte4,
	MSEHasGuidByte0,
	MSEHasGuidByte3,
	MSEHasGuidByte7,
	MSEHasGuidByte5,
	MSEHasGuidByte2,
	MSEGuidByte4,
	MSEGuidByte2,
	MSEUintCount,
	MSEGuidByte6,
	MSEGuidByte3,
	MSEGuidByte1,
	MSEGuidByte0,
	MSEGuidByte7,
	MSEGuidByte5,
	MSEEnd,
};
// 5.4.0
MovementStatusElements const MoveUnsetCanFly[] =
{
	MSEHasGuidByte6,
	MSEHasGuidByte5,
	MSEHasGuidByte0,
	MSEHasGuidByte4,
	MSEHasGuidByte3,
	MSEHasGuidByte7,
	MSEHasGuidByte2,
	MSEHasGuidByte1,
	MSEGuidByte4,
	MSEGuidByte5,
	MSEGuidByte7,
	MSECounter,
	MSEGuidByte6,
	MSEGuidByte2,
	MSEGuidByte3,
	MSEGuidByte1,
	MSEGuidByte0,
	MSEEnd,
};

// 4.3.4
MovementStatusElements const DismissControlledVehicle[] =
{
     MSEPositionX,
    MSEPositionZ,
    MSEPositionY,
    //MSEHasAliveTime,
    MSEHasGuidByte4,
    MSEHasGuidByte1,
    MSEHasGuidByte2,
    MSEHasGuidByte6,
    MSEZeroBit,
    MSEZeroBit,
    MSEHasTimestamp,
    MSEHasSplineElevation,
    MSEHasOrientation,
    MSEHasPitch,
    MSECounter,
    MSEHasMovementFlags2,
    MSEHasGuidByte3,
    MSEHasGuidByte7,
    MSEHasTransportData,
    MSEHasGuidByte0,
    MSEHasMovementFlags,
    MSEZeroBit,
    MSEHasFallData,
    MSEHasGuidByte5,

    MSEHasTransportGuidByte5,
    MSEHasTransportGuidByte4,
    MSEHasTransportGuidByte1,
    MSEHasTransportGuidByte3,
    MSEHasTransportGuidByte7,
    MSEHasTransportGuidByte2,
    MSEHasTransportGuidByte0,
    MSEHasTransportGuidByte6,
    MSEHasTransportTime2,
    MSEHasTransportTime3,

    MSEMovementFlags,
    MSEHasFallDirection,
    MSEMovementFlags2,

    MSEGuidByte4,
    //MSECounterUint32,
    MSEGuidByte6,
    MSEGuidByte3,
    MSEGuidByte2,
    MSEGuidByte0,
    MSEGuidByte5,
    MSEGuidByte7,
    MSEGuidByte1,

    MSETransportOrientation,
    MSETransportGuidByte0,
    MSETransportSeat,
    MSETransportGuidByte1,
    MSETransportGuidByte4,
    MSETransportTime3,
    MSETransportGuidByte5,
    MSETransportTime2,
    MSETransportGuidByte3,
    MSETransportGuidByte6,
    MSETransportPositionY,
    MSETransportPositionZ,
    MSETransportTime,
    MSETransportGuidByte7,
    MSETransportGuidByte2,
    MSETransportPositionX,

    MSEFallTime,
    MSEFallCosAngle,
    MSEFallSinAngle,
    MSEFallHorizontalSpeed,
    MSEFallVerticalSpeed,

    //MSEAliveTime,
    MSESplineElevation,
    MSEOrientation,
    MSEPitch,
    MSETimestamp,

    MSEEnd,
};

//5.1.0 16357 OK
MovementStatusElements const MoveUpdateTeleport[] =
{
    MSEHasSpline,
    MSEHasGuidByte5,
    MSEHasSplineElevation,
    MSEHasGuidByte2,
    MSEHasGuidByte1,
    MSEHasFallData,
    MSEHasTimestamp,
    MSEHasGuidByte4,
    //MSEHasCounter,
    MSEHasMovementFlags,
    MSEHasGuidByte6,
    MSEHasOrientation,
    MSEZeroBit,
    MSEHasFallDirection,
    MSEHasTransportData,
    MSEHasTransportGuidByte0,
    MSEHasTransportGuidByte6,
    MSEHasTransportGuidByte7,
    MSEHasTransportGuidByte5,
    MSEHasTransportTime3,
    MSEHasTransportGuidByte3,
    MSEHasTransportGuidByte1,
    MSEHasTransportTime2,
    MSEHasTransportGuidByte2,
    MSEHasTransportGuidByte4,
    //MSEHasATime,
    MSEHasMovementFlags2,
    MSEHasGuidByte3,
    MSEMovementFlags2,
    MSEMovementFlags,
    MSEHasPitch,
    MSEHasGuidByte7,
    MSEHasGuidByte0,
    MSEZeroBit,
    MSEPositionX,
    MSETransportGuidByte3,
    MSETransportTime2,
    MSETransportGuidByte0,
    MSETransportTime3,
    MSETransportTime,
    MSETransportGuidByte5,
    MSETransportPositionY,
    MSETransportPositionX,
    MSETransportOrientation,
    MSETransportPositionZ,
    MSETransportGuidByte4,
    MSETransportGuidByte2,
    MSETransportGuidByte7,
    MSETransportSeat,
    MSETransportGuidByte6,
    MSETransportGuidByte1,
    MSEPositionY,
    MSECounter,
    MSETimestamp,
    MSEGuidByte1,
    MSEFallHorizontalSpeed,
    MSEFallSinAngle,
    MSEFallCosAngle,
    MSEFallVerticalSpeed,
    MSEFallTime,
    MSEGuidByte3,
    MSEGuidByte4,
    MSEGuidByte5,
    MSEGuidByte7,
    MSEPositionZ,
    MSEPitch,
    MSEOrientation,
    MSEGuidByte6,
    MSEGuidByte2,
    MSEGuidByte0,
    //MSEATime,
    MSESplineElevation,
    MSEEnd,
};

MovementStatusElements const MoveCastSpell[] =
{
    MSEPositionZ,
    MSEPositionX,
	MSEPositionY,
	MSEHasGuidByte7,
    MSEHasSpline,
	MSEHasFallData,
    MSEHasGuidByte0,
	MSEHasMovementFlags,
	MSEHasTransportData,
	MSEHasGuidByte2,
	MSEZeroBit,
	MSEHasMovementFlags2,
	MSEHasGuidByte1,
	//MSEHasATime,
	MSEHasGuidByte3,
	MSEHasOrientation,
	MSEHasTimestamp,
    //MSEHasCounter,
    MSEHasGuidByte5,
	MSEHasGuidByte6,
	MSEHasPitch,
	MSEHasGuidByte4,
    MSEHasSplineElevation, 
    MSEZeroBit,
	MSEHasTransportTime2,
	MSEHasTransportGuidByte2,
	MSEHasTransportGuidByte3,
	MSEHasTransportGuidByte4,
	MSEHasTransportGuidByte0,
	MSEHasTransportGuidByte5,
    MSEHasTransportTime3,
	MSEHasTransportGuidByte6,
    MSEHasTransportGuidByte7,
    MSEHasTransportGuidByte1,
    MSEMovementFlags2,
    MSEHasFallDirection,
    MSEMovementFlags,
	MSEGuidByte1,
	MSEGuidByte2,
	MSEGuidByte5,
	MSECounter,
	MSEGuidByte6,
	MSEGuidByte7,
	MSEGuidByte4,
	MSEGuidByte0,
	MSEGuidByte3,
    MSETransportTime,
    MSETransportGuidByte5,
    MSETransportSeat,
	MSETransportOrientation,
	MSETransportGuidByte7,
	MSETransportGuidByte1,
	MSETransportPositionZ,
	MSETransportPositionX,
	MSETransportGuidByte6,
	MSETransportPositionY,
	MSETransportGuidByte4,
    MSETransportGuidByte2,
	MSETransportTime3,
	MSETransportTime2,
	MSETransportGuidByte0,
    MSETransportGuidByte3,
    //MSEATime,
    MSEOrientation,
	MSEFallTime,
	MSEFallCosAngle,
	MSEFallHorizontalSpeed,
    MSEFallSinAngle,
	MSEFallVerticalSpeed,
    MSETimestamp,
    MSEPitch,
    MSESplineElevation,
    MSEEnd,
};

// 5.4.0
MovementStatusElements const MoveSetFlightSpeed[] =
{
	MSEExtraElement,
	MSEUintCount,
	MSEHasGuidByte6,
	MSEHasGuidByte5,
	MSEHasGuidByte0,
	MSEHasGuidByte4,
	MSEHasGuidByte1,
	MSEHasGuidByte7,
	MSEHasGuidByte3,
	MSEHasGuidByte2,
	MSEGuidByte0,
	MSEGuidByte7,
	MSEGuidByte4,
	MSEGuidByte5,
	MSEGuidByte6,
	MSEGuidByte2,
	MSEGuidByte3,
	MSEGuidByte1,
	MSEEnd,
};

// 5.4.0
MovementStatusElements const MoveSetRunSpeed[] =
{
	MSEHasGuidByte1,
	MSEHasGuidByte7,
	MSEHasGuidByte4,
	MSEHasGuidByte2,
	MSEHasGuidByte5,
	MSEHasGuidByte3,
	MSEHasGuidByte6,
	MSEHasGuidByte0,
	MSEGuidByte1,
	MSECounter,
	MSEGuidByte7,
	MSEGuidByte3,
	MSEGuidByte0,
	MSEExtraElement,
	MSEGuidByte2,
	MSEGuidByte4,
	MSEGuidByte6,
	MSEGuidByte5,
	MSEEnd,
};

// 5.4.0
MovementStatusElements const MoveSetSwimSpeed[] =
{
	MSEExtraElement,
	MSECounter,
	MSEHasGuidByte4,
	MSEHasGuidByte7,
	MSEHasGuidByte6,
	MSEHasGuidByte3,
	MSEHasGuidByte5,
	MSEHasGuidByte2,
	MSEHasGuidByte0,
	MSEHasGuidByte1,
	MSEGuidByte1,
	MSEGuidByte6,
	MSEGuidByte5,
	MSEGuidByte2,
	MSEGuidByte0,
	MSEGuidByte3,
	MSEGuidByte4,
	MSEGuidByte7,
	MSEEnd,
};

void Movement::ExtraMovementStatusElement::ReadNextElement(ByteBuffer& packet)
{
    MovementStatusElements const element = _elements[_index++];

    switch (element)
    {
        case MSEHasGuidByte0:
        case MSEHasGuidByte1:
        case MSEHasGuidByte2:
        case MSEHasGuidByte3:
        case MSEHasGuidByte4:
        case MSEHasGuidByte5:
        case MSEHasGuidByte6:
        case MSEHasGuidByte7:
            Data.guid[element - MSEHasGuidByte0] = packet.ReadBit();
            break;
        case MSEGuidByte0:
        case MSEGuidByte1:
        case MSEGuidByte2:
        case MSEGuidByte3:
        case MSEGuidByte4:
        case MSEGuidByte5:
        case MSEGuidByte6:
        case MSEGuidByte7:
            packet.ReadByteSeq(Data.guid[element - MSEGuidByte0]);
            break;
        case MSEExtraFloat:
            packet >> Data.floatData;
            break;
        case MSEExtraInt8:
            packet >> Data.byteData;
            break;
        default:
            ASSERT(PrintInvalidSequenceElement(element, __FUNCTION__));
            break;
    }
}

void Movement::ExtraMovementStatusElement::WriteNextElement(ByteBuffer& packet)
{
    MovementStatusElements const element = _elements[_index++];

    switch (element)
    {
        case MSEHasGuidByte0:
        case MSEHasGuidByte1:
        case MSEHasGuidByte2:
        case MSEHasGuidByte3:
        case MSEHasGuidByte4:
        case MSEHasGuidByte5:
        case MSEHasGuidByte6:
        case MSEHasGuidByte7:
            packet.WriteBit(Data.guid[element - MSEHasGuidByte0]);
            break;
        case MSEGuidByte0:
        case MSEGuidByte1:
        case MSEGuidByte2:
        case MSEGuidByte3:
        case MSEGuidByte4:
        case MSEGuidByte5:
        case MSEGuidByte6:
        case MSEGuidByte7:
            packet.WriteByteSeq(Data.guid[element - MSEGuidByte0]);
            break;
        case MSEExtraFloat:
            packet << Data.floatData;
            break;
        case MSEExtraInt8:
            packet << Data.byteData;
            break;
        default:
            ASSERT(PrintInvalidSequenceElement(element, __FUNCTION__));
            break;
    }
}

bool Movement::PrintInvalidSequenceElement(MovementStatusElements const element, char const* function)
{
    sLog->outError(LOG_FILTER_UNITS, "Incorrect sequence element %d detected at %s", element, function);
    return false;
}

Movement::PacketSender::PacketSender(Unit* unit, Opcodes serverControl, Opcodes playerControl, Opcodes broadcast /*= SMSG_PLAYER_MOVE*/, ExtraMovementStatusElement* extras /*= NULL*/)
    : _extraElements(extras), _unit(unit)
{
    if (unit->GetTypeId() == TYPEID_PLAYER && unit->ToPlayer()->m_mover->GetTypeId() == TYPEID_PLAYER)
    {
        _selfOpcode = playerControl;
        _broadcast = broadcast;
    }
    else
    {
        _selfOpcode = NULL_OPCODE;
        _broadcast = serverControl;
    }
}

void Movement::PacketSender::Send() const
{
    bool isPlayerMovement = false;
    if (Player* player = _unit->ToPlayer())
    {
        isPlayerMovement = player->m_mover->GetTypeId() == TYPEID_PLAYER;
        if (isPlayerMovement && _selfOpcode != NULL_OPCODE)
        {
            WorldPacket data(_selfOpcode);
            _unit->WriteMovementInfo(data, _extraElements);
            player->SendDirectMessage(&data);
        }
    }

    if (_broadcast != NULL_OPCODE)
    {
        ///! Need to reset current extra element index before writing another packet
        if (_extraElements)
            _extraElements->ResetIndex();

        WorldPacket data(_broadcast);
        _unit->WriteMovementInfo(data, _extraElements);
        _unit->SendMessageToSet(&data, !isPlayerMovement);
    }
}

MovementStatusElements const* GetMovementStatusElementsSequence(Opcodes opcode)
{
    switch (opcode)
    {
    case CMSG_MOVE_FALL_RESET:
        return MovementFallResetSequence;
    case MSG_MOVE_FALL_LAND:
        return MovementFallLandSequence;
    case MSG_MOVE_HEARTBEAT:
        return MovementHeartBeatSequence;
    case MSG_MOVE_JUMP:
        return MovementJumpSequence;
    case MSG_MOVE_SET_FACING:
        return MovementSetFacingSequence;
    case MSG_MOVE_SET_PITCH:
        return MovementSetPitchSequence;
    case MSG_MOVE_START_ASCEND:
        return MovementStartAscendSequence;
    case MSG_MOVE_START_BACKWARD:
        return MovementStartBackwardSequence;
    case MSG_MOVE_START_DESCEND:
        return MovementStartDescendSequence;
    case MSG_MOVE_START_FORWARD:
        return MovementStartForwardSequence;
    case MSG_MOVE_START_PITCH_DOWN:
        return MovementStartPitchDownSequence;
    case MSG_MOVE_START_PITCH_UP:
        return MovementStartPitchUpSequence;
    case MSG_MOVE_START_STRAFE_LEFT:
        return MovementStartStrafeLeftSequence;
    case MSG_MOVE_START_STRAFE_RIGHT:
        return MovementStartStrafeRightSequence;
    case MSG_MOVE_START_SWIM:
        return MovementStartSwimSequence;
    case MSG_MOVE_START_TURN_LEFT:
        return MovementStartTurnLeftSequence;
    case MSG_MOVE_START_TURN_RIGHT:
        return MovementStartTurnRightSequence;
    case MSG_MOVE_STOP:
        return MovementStopSequence;
    case MSG_MOVE_STOP_ASCEND:
        return MovementStopAscendSequence;
    case MSG_MOVE_STOP_PITCH:
        return MovementStopPitchSequence;
    case MSG_MOVE_STOP_STRAFE:
        return MovementStopStrafeSequence;
    case MSG_MOVE_STOP_SWIM:
        return MovementStopSwimSequence;
    case MSG_MOVE_STOP_TURN:
        return MovementStopTurnSequence;
   // case SMSG_PLAYER_MOVE:
   //     return PlayerMoveSequence;
    case CMSG_MOVE_CHNG_TRANSPORT:
        return MoveChngTransport;
    case CMSG_MOVE_SPLINE_DONE:
        return MoveSplineDone;
    //case CMSG_MOVE_NOT_ACTIVE_MOVER:
     //   return MoveNotActiveMover;
	//case SMSG_MOVE_SET_CAN_FLY:
    //        return MoveSetCanFly;
   // case SMSG_MOVE_UNSET_CAN_FLY:
     //       return MoveUnsetCanFly;
    //case CMSG_DISMISS_CONTROLLED_VEHICLE:
        //return DismissControlledVehicle;
   // case SMSG_MOVE_UPDATE_TELEPORT:
//return MoveUpdateTeleport;
	case CMSG_CAST_SPELL:
		return MoveCastSpell;
	//case SMSG_MOVE_SET_FLIGHT_SPEED:
      //   return MoveSetFlightSpeed;
	//case SMSG_MOVE_SET_RUN_SPEED:
    //    return MoveSetRunSpeed;
	//case SMSG_MOVE_SET_SWIM_SPEED: // Still need more
     //   return MoveSetSwimSpeed;
    default:
        break;
    }

    return NULL;
}

