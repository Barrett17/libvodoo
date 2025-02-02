//	Copyright (c) 1998-99, Be Incorporated, All Rights Reserved.
//	SMS
/*	EMBeAnalogConsumerNode.h	*/

#ifndef EM_BE_ANALOG_CONSUMER_NODE
#define EM_BE_ANALOG_CONSUMER_NODE
#include "EMBeVideoDisplayer.h"

#include <View.h>
#include <Bitmap.h>
#include <Window.h>
#include <MediaNode.h>
#include <TranslationKit.h>
#include <BufferConsumer.h>
#include <TimedEventQueue.h>
#include <MediaEventLooper.h>
#include <StringView.h>

class EMProjectDataLoader;
class EMProjectDataSaver;
class VideoRealInput;


class EMBeAnalogConsumerNode : public BMediaEventLooper, public BBufferConsumer
{
public:
	EMBeAnalogConsumerNode(const char * name, BMediaAddOn *addon, const uint32 internal_id, media_output* p_spPhysicalInOutput);
	~EMBeAnalogConsumerNode();
	
/*	BMediaNode */
public:
	
	virtual	BMediaAddOn	*AddOn(long *cookie) const;
	
protected:

	virtual void		Start(bigtime_t performance_time);
	virtual void		Stop(bigtime_t performance_time, bool immediate);
//	virtual void		Seek(bigtime_t media_time, bigtime_t performance_time);
//	virtual void		TimeWarp(bigtime_t at_real_time, bigtime_t to_performance_time);

	virtual void		NodeRegistered();
	virtual	status_t 	RequestCompleted(
							const media_request_info & info);
							
	virtual	status_t 	HandleMessage(
							int32 message,
							const void * data,
							size_t size);

//	virtual status_t	DeleteHook(BMediaNode * node);

/*  BMediaEventLooper */
protected:
	virtual void		HandleEvent(
							const media_timed_event *event,
							bigtime_t lateness,
							bool realTimeEvent);
/*	BBufferConsumer */
public:
	
	virtual	status_t	AcceptFormat(
							const media_destination &dest,
							media_format * format);
	virtual	status_t	GetNextInput(
							int32 * cookie,
							media_input * out_input);
							
	virtual	void		DisposeInputCookie(
							int32 cookie);
	
protected:

	virtual	void		BufferReceived(
							BBuffer * buffer);
	
private:

	virtual	void		ProducerDataStatus(
							const media_destination &for_whom,
							int32 status,
							bigtime_t at_media_time);									
	virtual	status_t	GetLatencyFor(
							const media_destination &for_whom,
							bigtime_t * out_latency,
							media_node_id * out_id);
	virtual	status_t	Connected(
							const media_source &producer,
							const media_destination &where,
							const media_format & with_format,
							media_input * out_input);							
	virtual	void		Disconnected(
							const media_source &producer,
							const media_destination &where);							
	virtual	status_t	FormatChanged(
							const media_source & producer,
							const media_destination & consumer, 
							int32 from_change_count,
							const media_format & format);
							
/*	implementation */

public:
	status_t	ChangeColorDepth(const media_format & with_format);
	void ChangeFormat(media_format p_sFormat);
	status_t	CreateBuffers(
	const	media_format & with_format);
							
	void	DeleteBuffers();
	bool 	Initialize(media_format& p_oFormat);
	bool 	DisconnectNode();
	bool	PrepareForRecording();
	bool ClearData();
	bool SaveData(EMProjectDataSaver* p_opSaver);
	bool LoadData(EMProjectDataLoader* p_opLoader);
	bool CloseFile();

	void Lock();
	void Unlock();


public:
	media_input		m_to;

private:
	BStringView	*		mStatusLine;
	uint32				mInternalID;
	BMediaAddOn			*mAddOn;

	int64 jakob;
	media_input				mIn;
	media_destination		mDestination;
	bigtime_t				mMyLatency;

	BBitmap					*mBitmap[3];
	BBufferGroup			*mBuffers;
	uint32					mBufferMap[3];	
	
	bool					mOurBuffers;

	bigtime_t				mRate;
	uint32					mImageFormat;
	int32					mTranslator;
	char					mFileNameText[64];
	char					mServerText[64];
	char					mLoginText[64];
	char					mPasswordText[64];	
	char					mDirectoryText[64];
	media_node			timesourceNode;
	media_output*		m_spPhysicalInOutput;
	EMBeVideoDisplayer* m_opReceiver;

	bool m_vReadyForWriting;
	
	string* m_opFamilyName;
	string* m_opVideoCodecName;
	string* m_opAudioCodecName;
	float m_vpQuality;
	bool m_vRenderVideo;
	media_format m_sFormat;
	BMediaTrack* m_opVideoTrack;
	media_file_format m_sFileFormat;	
	BMediaFile* m_opMediaFile;
	uint32 m_vRenderFileSequenceNumber;
	int32 m_vFrameCount;
	
};

#endif
