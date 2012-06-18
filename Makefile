NAME= libstilnovo
TYPE= SHARED
SRCS= EMThreadListener.cpp EMThread.cpp EMSemaphore.cpp EMProjectDataContainer.cpp EMBeResourceRepository.cpp EMBeSemaphore.cpp EMDebugOutput.cpp EMBeThread.cpp EMException.cpp EMExceptionHandler.cpp EMListener.cpp media/EMMediaProject.cpp EMListenerRepository.cpp media/EMRecording.cpp media/EMAudioClip.cpp media/EMBeBufferRepository.cpp media/EMBeMediaFile.cpp media/EMBeMediaFileManager.cpp media/EMBeMediaRenderingNode.cpp media/EMBeMediaSystemInspector.cpp media/EMBeMediaTimer.cpp media/EMBeMediaUtility.cpp media/EMBeMixFunctions.cpp media/EMBeOutputNode.cpp media/EMBitmapBuffer.cpp media/EMBufferDestination.cpp media/EMBufferRepository.cpp media/EMDescriptor.cpp media/EMDestructivePlugin.cpp media/EMEncoderDescriptor.cpp media/EMEncoderRepository.cpp media/EMFileInputDescriptor.cpp media/EMInputDescriptor.cpp media/EMInputRepository.cpp media/EMMediaAudioSignalMeter.cpp media/EMMediaBufferSource.cpp media/EMMediaClip.cpp media/EMMediaClipRepository.cpp media/EMMediaDataBuffer.cpp media/EMMediaDestinationRepository.cpp media/EMMediaEffectTrack.cpp media/EMMediaEffectTrackRepository.cpp media/EMMediaFile.cpp media/EMMediaFileManager.cpp media/EMMediaFileRepository.cpp media/EMMediaFormat.cpp media/EMMediaIDManager.cpp media/EMMediaInputAudioSignalMeter.cpp media/EMMediaItemContainer.cpp media/EMMediaMatrix.cpp media/EMMediaMetronome.cpp media/EMMediaPool.cpp media/EMMediaPoolEntry.cpp media/EMMediaSignalMeter.cpp media/EMMediaSignalMeterRepository.cpp media/EMMediaSystemInspector.cpp media/EMMediaTimer.cpp media/EMMediaTrack.cpp media/EMMediaTrackRepository.cpp media/EMMediaUtility.cpp media/EMNativePlugin.cpp media/EMNativePluginEntry.cpp media/EMOutputDescriptor.cpp media/EMOutputRepository.cpp media/EMPlugin.cpp media/EMPluginChain.cpp media/EMPluginEntry.cpp media/EMPluginRepository.cpp media/EMRealtimeEncoderDescriptor.cpp media/EMRealtimeInputDescriptor.cpp media/EMRealtimeOutputDescriptor.cpp media/audio/EMAudioClipMixer.cpp media/audio/EMAudioFileInputDescriptor.cpp media/audio/EMAudioMixFunctions.cpp media/audio/EMAudioSignalMeter.cpp media/audio/EMBeAudioClipRepository.cpp media/audio/EMBeAudioConsumerNode.cpp media/audio/EMBeAudioFileInputDescriptor.cpp media/audio/EMBeAudioOutputNode.cpp media/audio/EMBeRealtimeAudioInputDescriptor.cpp media/audio/EMBeRealtimeAudioOutputDescriptor.cpp media/audio/EMDestructiveCrop.cpp media/audio/EMDestructiveFadeIn.cpp media/audio/EMDestructiveFadeOut.cpp media/audio/EMDestructiveNormalize.cpp media/audio/EMDestructiveReverse.cpp media/audio/EMDestructiveSilence.cpp media/audio/EMDSCache.cpp media/audio/EMEqualizerPlugin.cpp media/audio/EMMediaPoolAudioEntry.cpp media/audio/EMSilentAudioSource.cpp media/audio/EMWaveFileReader.cpp media/audio/EMWaveFileWriter.cpp
RSRCS=
LIBS= /boot/develop/lib/x86/libroot.so /boot/develop/lib/x86/libbe.so /boot/develop/lib/x86/libsupc++.so
LIBPATHS=
SYSTEM_INCLUDE_PATHS= /boot/develop/headers/be /boot/develop/headers/cpp /boot/develop/headers/posix /boot/home/config/include
LOCAL_INCLUDE_PATHS= media media/audio include media/midi media/video
OPTIMIZE=NONE
#	specify any preprocessor symbols to be defined.  The symbols will not
#	have their values set automatically; you must supply the value (if any)
#	to use.  For example, setting DEFINES to "DEBUG=1" will cause the
#	compiler option "-DDEBUG=1" to be used.  Setting DEFINES to "DEBUG"
#	would pass "-DDEBUG" on the compiler's command line.
DEFINES=
#	specify special warning levels
#	if unspecified default warnings will be used
#	NONE = supress all warnings
#	ALL = enable all warnings
WARNINGS =
# Build with debugging symbols if set to TRUE
SYMBOLS=
COMPILER_FLAGS=
LINKER_FLAGS=

## include the makefile-engine
include $(BUILDHOME)/etc/makefile-engine
