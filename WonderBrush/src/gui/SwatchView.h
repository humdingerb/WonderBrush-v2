// SwatchView.h

#ifndef SWATCH_VIEW_H
#define SWATCH_VIEW_H

#include <View.h>

#include <layout.h>

enum {
	MSG_COLOR_DROP				= 'PSTE',
};

class SwatchView : public MView, public BView {
 public:
								SwatchView(const char* name,
										   BMessage* message,
										   BHandler* target,
										   rgb_color color,
										   float width = 24.0,
										   float height = 24.0);
	virtual						~SwatchView();

								// MView
	virtual	minimax				layoutprefs();
	virtual	BRect				layout(BRect frame);

								// BView
	virtual	void				Draw(BRect updateRect);
	virtual	void				MessageReceived(BMessage* message);

	virtual	void				MouseDown(BPoint where);
	virtual	void				MouseUp(BPoint where);
	virtual	void				MouseMoved(BPoint where, uint32 transit,
										   const BMessage* dragMessage);

								// SwatchView
			void				SetColor(rgb_color color);
			rgb_color			Color() const
									{ return fColor; }

			void				SetClickedMessage(BMessage* message);
			void				SetDroppedMessage(BMessage* message);

 private:
			void				_Invoke(const BMessage* message);
			void				_StrokeRect(BRect frame, rgb_color leftTop,
										   rgb_color rightBottom);
			void				_DragColor();

			rgb_color			fColor;
			BPoint				fTrackingStart;
			bool				fActive;
			bool				fDropInvokes;

			BMessage*			fClickMessage;
			BMessage*			fDroppedMessage;
			BHandler*			fTarget;

			float				fWidth;
			float				fHeight;
};

#endif // SWATCH_VIEW_H
